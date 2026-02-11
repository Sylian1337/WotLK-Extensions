-- DBC Management Tab
function SylianDevAddon:LoadDBCTab(parent)
    local yOffset = -10
    
    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffDBC Hot Reload Tools|r")
    yOffset = yOffset - 30
    
    -- Spell DBC Reload
    local spellBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    spellBtn:SetSize(200, 30)
    spellBtn:SetPoint("TOP", 0, yOffset)
    spellBtn:SetText("Reload Spell.dbc")
    spellBtn:SetScript("OnClick", function()
        if HotReloadSpellDBC then
            local success = HotReloadSpellDBC()
            print("|cff" .. (success and "00ff00" or "ff0000") .. 
                  "Spell.dbc reload " .. (success and "successful!" or "failed!") .. "|r")
        else
            print("|cffff0000HotReloadSpellDBC function not found|r")
        end
    end)
    yOffset = yOffset - 40
    
    -- Item DBC Reload
    local itemBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    itemBtn:SetSize(200, 30)
    itemBtn:SetPoint("TOP", 0, yOffset)
    itemBtn:SetText("Reload Item.dbc")
    itemBtn:SetScript("OnClick", function()
        if ChangeSpellVisual then
            local success = ChangeSpellVisual()
            print("|cff" .. (success and "00ff00" or "ff0000") .. 
                  "Item.dbc reload " .. (success and "successful!" or "failed!") .. "|r")
        else
            print("|cffff0000HotReloadItemDBC function not found|r")
        end
    end)
    yOffset = yOffset - 40
    
    -- HotPatch Item Name
    local hotpatchBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    hotpatchBtn:SetSize(200, 30)
    hotpatchBtn:SetPoint("TOP", 0, yOffset)
    hotpatchBtn:SetText("HotPatch Item Name")
    hotpatchBtn:SetScript("OnClick", function()
        if HotPatchItem then
            local success, oldName, newName = HotPatchItem()
            if success then
                print("|cff00ff00Item name changed from '" .. (oldName or "?") .. 
                      "' to '" .. (newName or "?") .. "'|r")
            else
                print("|cffff0000HotPatchItem failed|r")
            end
        else
            print("|cffff0000HotPatchItem function not found|r")
        end
    end)
end