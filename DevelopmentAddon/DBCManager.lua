-- DBC Management Tab
function SylianDevAddon:LoadDBCTab(parent)
    local yOffset = -10

    -- Title
    local title = parent:CreateFontString(nil, "OVERLAY", "GameFontNormal")
    title:SetPoint("TOP", 0, yOffset)
    title:SetText("|cff00ccffDBC Hot Reload Tool|r")
    yOffset = yOffset - 30

    -- Define reloadDBC function FIRST so it's available to the UI controls
    local statusText -- forward declaration (will be created later)
    local function reloadDBC(inputText)
        local name = inputText

        -- Trim whitespace
        if name and name:match("^%s*$") then
            name = nil
        end

        if name then
            if HotReloadDBC then
                HotReloadDBC(name)
                statusText:SetText("Reloading DBC: " .. name)
                statusText:SetTextColor(0, 1, 0)  -- green
            else
                statusText:SetText("Error: HotReloadDBC not available")
                statusText:SetTextColor(1, 0, 0)  -- red
                print("HotReloadDBC function not available.")
            end
        else
            if HotReloadDBC then
                HotReloadDBC()
                statusText:SetText("Reloading all DBCs...")
                statusText:SetTextColor(0, 1, 0)  -- green
            else
                statusText:SetText("Error: HotReloadDBC not available")
                statusText:SetTextColor(1, 0, 0)  -- red
                print("HotReloadDBC function not available.")
            end
        end
    end

    -- Now create UI elements that use reloadDBC

    -- DBC Name input box
    local editBox = CreateFrame("EditBox", nil, parent, "InputBoxTemplate")
    editBox:SetSize(200, 24)
    editBox:SetPoint("TOP", 0, yOffset)
    editBox:SetAutoFocus(false)
    editBox:SetScript("OnEnterPressed", function(self)
        self:ClearFocus()
        reloadDBC(editBox:GetText())   -- reloadDBC is captured from the outer scope
    end)
    yOffset = yOffset - 30

    -- DBC Reload button
    local dbcReloadBtn = CreateFrame("Button", nil, parent, "UIPanelButtonTemplate")
    dbcReloadBtn:SetSize(200, 30)
    dbcReloadBtn:SetPoint("TOP", 0, yOffset)
    dbcReloadBtn:SetText("Reload DBC")
    dbcReloadBtn:SetScript("OnClick", function()
        reloadDBC(editBox:GetText())
    end)
    yOffset = yOffset - 40

    -- Status text (now we can create it and assign to statusText)
    statusText = parent:CreateFontString(nil, "OVERLAY", "GameFontNormalSmall")
    statusText:SetPoint("TOP", 0, yOffset)
    statusText:SetText("")
    statusText:SetTextColor(1, 1, 1)
    yOffset = yOffset - 20
end