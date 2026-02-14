-- Transmog Tab (Now only runs once at startup)
function SylianDevAddon:LoadTransmogTab(parent)
    local yOffset = -10
    
    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffTransmog System|r")
    yOffset = yOffset - 30
    
    -- Info text
    local infoText = parent:CreateFontString(nil, "OVERLAY", "GameFontHighlight")
    infoText:SetPoint("TOP", 0, yOffset)
    infoText:SetText("Transmog functionality coming soon...")
    infoText:SetTextColor(0.7, 0.7, 0.7)
    yOffset = yOffset - 40
    
    -- Test Model Attachment Button
    local attachBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    attachBtn:SetSize(200, 30)
    attachBtn:SetPoint("TOP", 0, yOffset)
    attachBtn:SetText("Test Attach Model")
    attachBtn:SetScript("OnClick", function()
        if _G["AttachToParentTestingFunction"] then
            _G["AttachToParentTestingFunction"]()
            print("|cff00ccffAttempting to attach model to player...|r")
        else
            print("|cffff0000AttachToParentTestingFunction function not found|r")
        end
    end)    
	yOffset = yOffset - 40
end