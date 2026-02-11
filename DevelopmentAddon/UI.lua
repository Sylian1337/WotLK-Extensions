-- Main UI Window
function SylianDevAddon:ShowUI()
    if not SylianDevAddon.MainFrame then
        self:CreateMainFrame()
    end
    SylianDevAddon.MainFrame:Show()
end

function SylianDevAddon:HideUI()
    if SylianDevAddon.MainFrame then
        SylianDevAddon.MainFrame:Hide()
    end
end

function SylianDevAddon:CreateMainFrame()
    -- Create frame
    local frame = CreateFrame("Frame", "SylianDevAddonFrame", UIParent)
    frame:SetSize(SylianDevAddonDB.windowSize.width, SylianDevAddonDB.windowSize.height)
    frame:SetPoint(SylianDevAddonDB.windowPosition.point, 
                   SylianDevAddonDB.windowPosition.x, 
                   SylianDevAddonDB.windowPosition.y)
    
    frame:SetBackdrop({
        bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background",
        edgeFile = "Interface\\DialogFrame\\UI-DialogBox-Border",
        tile = true, tileSize = 32, edgeSize = 32,
        insets = { left = 11, right = 12, top = 12, bottom = 11 }
    })
    frame:SetBackdropColor(0, 0, 0, 0.9)
    
    -- Title
    local title = frame:CreateFontString(nil, "OVERLAY", "GameFontNormalLarge")
    title:SetPoint("TOP", 0, -15)
    title:SetText("|cff00ccffSylian Development Tools|r")
    
    -- Close button
    local closeBtn = CreateFrame("Button", nil, frame, "UIPanelCloseButton")
    closeBtn:SetPoint("TOPRIGHT", -5, -5)
    closeBtn:SetScript("OnClick", function() self:HideUI() end)
    
    -- Tab Definitions
    local tabData = {
        {name = "DBC Tools"},
        {name = "Player"},
        {name = "Transmog"},
        {name = "Debug"},
    }
    
    -- We will store the container frames here
    frame.tabFrames = {}
    
    -- Create tab buttons and their corresponding content containers
    local lastTab
    for i, data in ipairs(tabData) do
        -- 1. Create the Button
        local tabBtn = CreateFrame("Button", "SylianDevTab"..i, frame, "UIPanelButtonTemplate")
        tabBtn:SetSize(80, 25)
        tabBtn:SetText(data.name)
        
        if i == 1 then
            tabBtn:SetPoint("TOPLEFT", 10, -45)
        else
            tabBtn:SetPoint("LEFT", lastTab, "RIGHT", 5, 0)
        end
        
        -- 2. Create the Content Container for this specific tab
        local content = CreateFrame("Frame", nil, frame)
        content:SetPoint("TOPLEFT", 10, -75)
        content:SetPoint("BOTTOMRIGHT", -10, 10)
        content:Hide() -- Hide by default
        
        -- Optional: Background for the content area
        local bg = content:CreateTexture(nil, "BACKGROUND")
        bg:SetAllPoints(true)
        bg:SetTexture(0.1, 0.1, 0.1, 0.5)
        
        frame.tabFrames[i] = content
        lastTab = tabBtn

        tabBtn:SetScript("OnClick", function()
            self:ShowTab(i)
        end)
    end
    
    -- Make draggable
    frame:SetMovable(true)
    frame:EnableMouse(true)
    frame:RegisterForDrag("LeftButton")
    frame:SetScript("OnDragStart", function(self) self:StartMoving() end)
    frame:SetScript("OnDragStop", function(self)
        self:StopMovingOrSizing()
        local point, _, relativePoint, x, y = self:GetPoint()
        SylianDevAddonDB.windowPosition = { point = point, x = x, y = y }
    end)
    
    SylianDevAddon.MainFrame = frame
    
    -- Initialize the content of each tab ONCE
    self:LoadDBCTab(frame.tabFrames[1])
    self:LoadPlayerTab(frame.tabFrames[2])
    self:LoadTransmogTab(frame.tabFrames[3])
    self:LoadDebugTab(frame.tabFrames[4])

    -- Show first tab
    self:ShowTab(1)
end

function SylianDevAddon:ShowTab(tabIndex)
    if not SylianDevAddon.MainFrame or not SylianDevAddon.MainFrame.tabFrames then
        return
    end
    
    -- Hide all tab containers
    for i, tabFrame in ipairs(SylianDevAddon.MainFrame.tabFrames) do
        tabFrame:Hide()
    end
    
    -- Show the selected container
    if SylianDevAddon.MainFrame.tabFrames[tabIndex] then
        SylianDevAddon.MainFrame.tabFrames[tabIndex]:Show()
    end
end

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
    attachBtn:SetText("Test Model Attachment")
    attachBtn:SetScript("OnClick", function()
        if _G["ChangeSpellVisual"] then
            _G["ChangeSpellVisual"]()
            print("|cff00ccffAttempting to attach model to player...|r")
        else
            print("|cffff0000ChangeSpellVisual function not found|r")
        end
    end)
end

-- Note: Make sure you update LoadDBCTab, LoadPlayerTab, and LoadDebugTab 
-- to use the 'parent' passed to them, similar to the Transmog tab above.