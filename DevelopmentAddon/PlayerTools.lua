-- Player Information Tab
function SylianDevAddon:LoadPlayerTab(parent)
    local yOffset = -10
    
    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffPlayer Information|r")
    yOffset = yOffset - 30
    
    -- Get Player Address
    local addrBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    addrBtn:SetSize(200, 30)
    addrBtn:SetPoint("TOP", 0, yOffset)
    addrBtn:SetText("Get Player Address")
    addrBtn:SetScript("OnClick", function()
        if GetLocalPlayer then
            local addr = GetLocalPlayer()
            print("|cff00ccffPlayer Address:|r " .. tostring(addr))
        else
            print("|cffff0000GetLocalPlayer function not found|r")
        end
    end)
    yOffset = yOffset - 40
    
    -- Get Target GUID
    local targetBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    targetBtn:SetSize(200, 30)
    targetBtn:SetPoint("TOP", 0, yOffset)
    targetBtn:SetText("Get Target GUID")
    targetBtn:SetScript("OnClick", function()
        local target = UnitName("target")
        if target then
            local guid = UnitGUID("target")
            print("|cff00ccffTarget:|r " .. target)
            print("|cff00ccffGUID:|r " .. (guid or "N/A"))
        else
            print("|cffff0000No target selected|r")
        end
    end)
    yOffset = yOffset - 40
    
    -- Coordinates Display
    local coordsFrame = CreateFrame("Frame", nil, parent)
    coordsFrame:SetSize(200, 60)
    coordsFrame:SetPoint("TOP", 0, yOffset)
    
    local coordsTitle = coordsFrame:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    coordsTitle:SetPoint("TOP", 0, 0)
    coordsTitle:SetText("|cff00ccffPlayer Coordinates|r")
    
    local coordsText = coordsFrame:CreateFontString(nil, "OVERLAY", "GameFontHighlight")
    coordsText:SetPoint("CENTER", 0, -15)
    coordsText:SetText("Loading...")
    
    coordsFrame:SetScript("OnUpdate", function(self, elapsed)
        self.elapsed = (self.elapsed or 0) + elapsed
        if self.elapsed > 0.5 then  -- Update every 0.5 seconds
            local x, y = GetPlayerMapPosition("player")
            local zone = GetZoneText()
            if x and y and zone then
                coordsText:SetText(string.format("%s\nX: %.1f, Y: %.1f", zone, x*100, y*100))
            end
            self.elapsed = 0
        end
    end)
end