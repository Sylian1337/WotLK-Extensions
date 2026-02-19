#include "CustomPacket.h"
#include "Player.h"

/*
    Apply()

    This function patches (hooks) the WoW 3.3.5a client so that:
    - Our code runs instead of Blizzard's at specific points
    - We can intercept incoming server packets (SMSG)
    - We can register handlers for custom SMSG opcodes
*/
void CustomPacket::Apply()
{
    /*
        Hook player initialization.

        Blizzard normally calls ClientServices::InitializePlayer().
        We redirect that call so InitializePlayerEx() runs instead.

        IMPORTANT:
        InitializePlayerEx() MUST call the original function internally,
        or the client will break.
    */
    Util::OverwriteUInt32AtAddress(
        0x6E8EE2,
        (uint32_t)&InitializePlayerEx - 0x6E8EE6
    );

    /*
        Hook multiple call sites of CNetClient::ProcessMessage.

        These are different execution paths where incoming SMSG packets
        are dispatched. By redirecting them to ProcessMessageEx(),
        we get first look at ALL incoming packets.
    */
    Util::OverwriteUInt32AtAddress(0x6324CA, (uint32_t)&ProcessMessageEx - 0x6324CE);
    Util::OverwriteUInt32AtAddress(0x714AFC, (uint32_t)&ProcessMessageEx - 0x714B00);
    Util::OverwriteUInt32AtAddress(0x716A79, (uint32_t)&ProcessMessageEx - 0x716A7D);

    /*
        Hook CNetClient::SetMessageHandler.

        This allows us to register handlers for custom SMSG opcodes
        without touching Blizzard's internal handler table.
    */
    Util::OverwriteUInt32AtAddress(
        0x6B0B9E,
        (uint32_t)&SetMessageHandlerEx - 0x6B0BA2
    );
}

/*
    Registers all custom SMSG handlers.

    This is called once after player initialization.
*/
void CustomPacket::SetCustomHandlers()
{
    /*
        Register a handler for SMSG_UPDATE_CUSTOM_COMBAT_RATING.

        When the server sends opcode 1311,
        Packet_SMSG_UPDATE_CUSTOM_COMBAT_RATING() will be called.
    */
    SetMessageHandlerEx(
        nullptr,
        0,
        SMSG_UPDATE_CUSTOM_COMBAT_RATING,
        &Packet_SMSG_UPDATE_CUSTOM_COMBAT_RATING,
        0
    );
}

/*
    Our replacement for ClientServices::InitializePlayer.
*/
void CustomPacket::InitializePlayerEx()
{
    // Call Blizzard's original player initialization
    ClientServices::InitializePlayer();

    // Register our custom SMSG handlers
    SetCustomHandlers();
}

/*
    ProcessMessageEx()

    This function intercepts ALL incoming server packets (SMSG).
    It decides whether Blizzard handles the packet,
    or whether it belongs to our custom SMSG system.
*/
void __fastcall CustomPacket::ProcessMessageEx(
    void* _this,
    uint32_t unused,
    uint32_t a2,
    CDataStore* a3,
    uint32_t a4
)
{
    int16_t opcode = 0;

    // Read the opcode from the incoming packet
    CDataStore_C::GetInt16(a3, &opcode);

    /*
        If the opcode is below our custom SMSG base,
        this is a normal Blizzard packet.
    */
    if (opcode < CUSTOM_SMSG_BASE)
    {
        // Rewind read pointer so Blizzard can reread the opcode
        a3->m_read -= 2;

        // Let Blizzard handle it normally
        CNetClient::ProcessMessage(_this, a2, a3, a4);
    }
    else
    {
        // Blizzard internal statistic (not critical, but keep it)
        ++*(uint32_t*)0xC5D638;

        /*
            Convert opcode to handler array index.

            Example:
                opcode 1311 -> index 0
                opcode 1312 -> index 1
        */
        uint32_t num = opcode - CUSTOM_SMSG_BASE;

        // Number of valid custom SMSG handlers
        uint32_t maxCustom = NUM_CUSTOM_SMSG_OPCODES - CUSTOM_SMSG_BASE;

        /*
            If a handler exists for this custom SMSG,
            call it.
        */
        if (num < maxCustom && customData.handler[num])
        {
            ((void(*)(void*, uint32_t, uint32_t, CDataStore*))
                customData.handler[num])(
                    customData.handlerParam[num],
                    opcode,
                    a2,
                    a3
                    );
        }
        else
        {
            /*
                Unknown or unhandled custom SMSG.

                Mark packet as read so it doesn't break the stream.
            */
            ((void(*__thiscall)(CDataStore*))a3->vTable->fn_IsRead)(a3);
        }
    }
}

/*
    SetMessageHandlerEx()

    Registers handlers for both Blizzard SMSGs and custom SMSGs.
*/
void __fastcall CustomPacket::SetMessageHandlerEx(
    void* _this,
    uint32_t unused,
    uint32_t opcode,
    void* handler,
    void* param
)
{
    /*
        Blizzard SMSGs go into Blizzard's handler table.
    */
    if (opcode < CUSTOM_SMSG_BASE)
    {
        CNetClient::SetMessageHandler(_this, opcode, handler, param);
    }
    else
    {
        /*
            Custom SMSGs go into our own handler arrays.
        */
        uint32_t num = opcode - CUSTOM_SMSG_BASE;
        customData.handler[num] = handler;
        customData.handlerParam[num] = param;
    }
}

/*
    Handler for SMSG_UPDATE_CUSTOM_COMBAT_RATING.

    This is called when the server sends opcode 1311.
*/
void CustomPacket::Packet_SMSG_UPDATE_CUSTOM_COMBAT_RATING(
    void* handlerParam,
    uint32_t opcode,
    uint32_t a2,
    CDataStore* a3
)
{
    int8_t ratingID = 0;
    int32_t ratingAmount = 0;

    // Read payload
    CDataStore_C::GetInt8(a3, &ratingID);
    CDataStore_C::GetInt32(a3, &ratingAmount);

    // Apply the custom combat rating to client-side fields
    if (ratingID > -1 && ratingID < 7)
    {
        if (ratingAmount > -1)
            CustomFields::SetCustomCombatRating(ratingID, ratingAmount);
        else
            CustomFields::SetCustomCombatRating(ratingID, 0);
    }
}

/*
    Sends a custom CMSG from client to server.

    This packet has NO Blizzard meaning.
    Only your custom server code reacts to it.
*/
void CustomPacket::Send_CMSG_CUSTOM_SYLIAN_PACKET()
{
    CDataStore pkt;

    // Initialize outgoing packet
    CDataStore_C::GenPacket(&pkt);

    // Write the CMSG opcode (int32!)
    CDataStore_C::PutInt32(&pkt, CMSG_EXAMPLE_PACKET);

    // Reset read pointer (important for SendPacket)
    pkt.m_read = 0;

    // Send packet to server
    ClientServices::SendPacket(&pkt);

    // Free packet memory
    CDataStore_C::Release(&pkt);
}
