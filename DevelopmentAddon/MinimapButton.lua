-- Minimap Button
function SylianDevAddon:CreateMinimapButton()
    local button = CreateFrame("Button", "SylianDevMinimapButton", Minimap)
    button:SetSize(32, 32)
    button:SetPoint("TOPLEFT", Minimap, "TOPLEFT", 0, 0)
    
    button:SetNormalTexture("Interface\\AddOns\\SylianDevAddon\\Textures\\icon.tga")
    button:SetHighlightTexture("Interface\\Minimap\\UI-Minimap-ZoomButton-Highlight")
    
    button:SetScript("OnClick", function(self, button)
        if button == "LeftButton" then
            SylianDevAddon:ToggleUI()
        elseif button == "RightButton" then
            -- Show options menu
            local menu = {
                {text = "Show Window", func = function() SylianDevAddon:ShowUI() end},
                {text = "Hide Window", func = function() SylianDevAddon:HideUI() end},
                {text = "Reload UI", func = function() ReloadUI() end},
                {text = "Settings", func = function() print("Settings coming soon") end},
            }
            EasyMenu(menu, SylianDevMinimapButtonMenu, "cursor", 0, 0, "MENU")
        end
    end)
    
    button:SetScript("OnEnter", function(self)
        GameTooltip:SetOwner(self, "ANCHOR_LEFT")
        GameTooltip:SetText("Sylian Dev Addon")
        GameTooltip:AddLine("Left-click: Toggle window", 1, 1, 1)
        GameTooltip:AddLine("Right-click: Options", 1, 1, 1)
        GameTooltip:Show()
    end)
    
    button:SetScript("OnLeave", function(self)
        GameTooltip:Hide()
    end)
end

function SylianDevAddon:ToggleUI()
    if SylianDevAddon.MainFrame and SylianDevAddon.MainFrame:IsShown() then
        self:HideUI()
    else
        self:ShowUI()
    end
end