/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** addon_manager.c
*/

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "../include/gertrude.h"

void addons_init(lua_State *L)
{
    L = luaL_newstate();
    luaL_openlibs(L);
    if (luaL_loadfile(L, "/opt/gertrude-cli/addons/init.lua"))
        bail(L, "1 - init");
    if (lua_pcall(L, 0, 0, 0))
        bail(L, "2 - Priming Run");
}

void call_addons(lua_State *L, int g_timing)
{
    lua_getglobal(L, "call_addon");
    lua_pushnumber(L, g_timing);
    if (lua_pcall(L, 1, 0, 0))
        bail(L, "3 - call");
}
