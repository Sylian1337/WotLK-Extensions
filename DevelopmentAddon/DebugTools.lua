-- Debug Tools Tab
function SylianDevAddon:LoadDebugTab(parent)
    local yOffset = -10
    
    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffDebugging Tools|r")
    yOffset = yOffset - 30
    
    -- Reload UI Button
    local reloadBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    reloadBtn:SetSize(200, 30)
    reloadBtn:SetPoint("TOP", 0, yOffset)
    reloadBtn:SetText("Reload UI")
    reloadBtn:SetScript("OnClick", function()
        ReloadUI()
    end)
    yOffset = yOffset - 40
    
    -- Dump Memory Info
    local dumpBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    dumpBtn:SetSize(200, 30)
    dumpBtn:SetPoint("TOP", 0, yOffset)
    dumpBtn:SetText("Dump Memory Info")
    dumpBtn:SetScript("OnClick", function()
        print("|cff00ccff=== Memory Information ===|r")
        print("Collectgarbage('count'): " .. collectgarbage("count") .. " KB")
        
        -- List loaded addons
        print("|cff00ccffLoaded Addons:|r")
        for i = 1, GetNumAddOns() do
            if IsAddOnLoaded(i) then
                local name, _, _, _, _, _ = GetAddOnInfo(i)
                print("  " .. name)
            end
        end
    end)
    yOffset = yOffset - 40
    
    -- Test Lua Function
    local testBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    testBtn:SetSize(200, 30)
    testBtn:SetPoint("TOP", 0, yOffset)
    testBtn:SetText("Test Lua Functions")
    testBtn:SetScript("OnClick", function()
        print("|cff00ccff=== Lua Function Test ===|r")
        
        -- Test basic functions
        local funcs = {
            "GetLocalPlayer",
            "HotReloadSpellDBC",
            "HotPatchItem",
            "ApplyTransmog"
        }
        
        for _, funcName in ipairs(funcs) do
            local exists = _G[funcName] ~= nil
            print(string.format("%s: %s", funcName, exists and "|cff00ff00✓ Found|r" or "|cffff0000✗ Missing|r"))
        end
    end)
end