--
-- GERTRUDE PROJECT, 2024
-- gertrude-cli
-- File description:
-- linker.lua
--

local function enum(tbl)
    local length = #tbl

    for i = 1, length do
        local v = tbl[i]
        tbl[v] = i
    end
    return tbl
end


---@class Event
---@field g_timing integer | boolean
---@field g_exec function
Event = {}

function Event:new(o, g_timing, g_exec)
    local new_event = o or {}

    setmetatable(new_event, self)
    self.g_timing = g_timing
    self.g_exec = g_exec
    return new_event
end

---@class linker
linker = {
    loop = {}, -- contains events that you iterate through
    timings = enum {
        "G_BEFORE_VAR",
        "G_AFTER_VAR",
        "G_BEFORE_REM",
        "G_AFTER_REM",
        "G_BEFORE_RULES",
        "G_AFTER_RULES",
        "G_BEFORE_DIR",
        "G_AFTER_DIR",
        "G_BEFORE_PHONY",
        "G_AFTER_PHONY",
        "G_BEFORE_HEADER",
        "G_AFTER_HEADER",
        "G_BEFORE_WARN",
        "G_AFTER_WARN",
        "G_BEFORE_ERR",
        "G_AFTER_ERR",
        "G_REPLACE",
    }
}
