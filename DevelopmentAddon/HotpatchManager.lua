-- Debug Tools Tab
function SylianDevAddon:LoadHotpachTool(parent)
    local yOffset = -10
    
    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffHotpatching Tool|r")
    yOffset = yOffset - 30
    
    -- Reload UI Button
    local enableHotPatchesBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    enableHotPatchesBtn:SetSize(200, 30)
    enableHotPatchesBtn:SetPoint("TOP", 0, yOffset)
    enableHotPatchesBtn:SetText("Enable Hotpatches")
    enableHotPatchesBtn:SetScript("OnClick", function()
        if _G["InstallAllHotpatches"] then
            _G["InstallAllHotpatches"]()
            print("|cff00ccffAll Hotpatches enabled!|r")
        else
            print("|cffff0000Enable All Hotpatches function not found|r")
        end
    end)    
    yOffset = yOffset - 40
    
    -- Dump Memory Info
    local disableHotPatchesBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    disableHotPatchesBtn:SetSize(200, 30)
    disableHotPatchesBtn:SetPoint("TOP", 0, yOffset)
    disableHotPatchesBtn:SetText("Disable Hotpatches")
    disableHotPatchesBtn:SetScript("OnClick", function()
        if _G["UninstallAllHotpatches"] then
            _G["UninstallAllHotpatches"]()
            print("|cff00ccffAll Hotpatches disabled!|r")
        else
            print("|cffff0000Disable All Hotpatches function not found|r")
        end
    end)    
    yOffset = yOffset - 40
end