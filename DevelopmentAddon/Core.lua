-- SylianDevAddon Core
SylianDevAddon = {}

-- Database
SylianDevAddonDB = SylianDevAddonDB or {
    windowPosition = { point = "CENTER", x = 0, y = 0 },
    windowSize = { width = 350, height = 500 },
    showMinimapButton = false, -- Disabled by default
    lastUsedFunctions = {},
}

-- Slash commands
SLASH_SYLIANDEV1 = "/syldev"
SLASH_SYLIANDEV2 = "/sylian"
SlashCmdList["SYLIANDEV"] = function(msg)
    if msg == "" or msg == "show" then
        SylianDevAddon:ShowUI()
    elseif msg == "hide" then
        SylianDevAddon:HideUI()
    elseif msg == "reset" then
        SylianDevAddon:ResetPosition()
    else
        print("|cff00ccffSylian Dev Addon|r Commands:")
        print("|cff00ccff/syldev show|r - Show the development window")
        print("|cff00ccff/syldev hide|r - Hide the window")
        print("|cff00ccff/syldev reset|r - Reset window position")
    end
end

-- Reset position function
function SylianDevAddon:ResetPosition()
    SylianDevAddonDB.windowPosition = { point = "CENTER", x = 0, y = 0 }
    SylianDevAddonDB.windowSize = { width = 350, height = 500 }
    if SylianDevAddon.MainFrame then
        SylianDevAddon.MainFrame:ClearAllPoints()
        SylianDevAddon.MainFrame:SetPoint("CENTER", 0, 0)
        SylianDevAddon.MainFrame:SetSize(350, 500)
    end
    print("|cff00ff00Window position reset|r")
end

-- Addon initialization
local frame = CreateFrame("Frame")
frame:RegisterEvent("ADDON_LOADED")
frame:SetScript("OnEvent", function(self, event, addonName)
    if addonName == "SylianDevAddon" then
        print("|cff00ccffSylian Development Addon|r v1.0 loaded!")
        print("Type |cff00ccff/syldev|r to open the window")
    end
end)