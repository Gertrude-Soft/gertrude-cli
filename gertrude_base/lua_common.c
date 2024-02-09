/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** addon_manager.c
*/

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <stdio.h>
#include <stdlib.h>

#include "../include/text_mod.h"

void bail(lua_State *L, char *error_code)
{
    fprintf(stderr, "\n%sADDON ERROR %s: %s\n%s", RED,
            error_code, lua_tostring(L, -1), NC);
    exit(84);
}
