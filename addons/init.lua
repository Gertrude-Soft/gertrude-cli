--
-- GERTRUDE PROJECT, 2024
-- gertrude-cli
-- File description:
-- init.lua
--

require("addons.linker")
LFS = require("lfs")

for file in LFS.dir("/opt/gertrude-cli/addons") do
    if LFS.attributes(file, "mode") == "directory" then
        require(file);
    end
end

local function call_addon(timing)
    for _, val in pairs(linker.loop) do
        if val.g_timing == timing then
            val.g_exec()
        end
    end
end

return call_addon
