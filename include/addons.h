/*
** GERTRUDE PROJECT, 2024
** gertrude-cli
** File description:
** addons.h
*/

#ifndef ADDONS_H_
    #define ADDONS_H_

typedef enum g_timings_e {
    G_BEFORE_VAR = 1,
    G_AFTER_VAR,
    G_BEFORE_REM,
    G_AFTER_REM,
    G_BEFORE_RULES,
    G_AFTER_RULES,
    G_BEFORE_DIR,
    G_AFTER_DIR,
    G_BEFORE_PHONY,
    G_AFTER_PHONY,
    G_BEFORE_HEADER,
    G_AFTER_HEADER,
    G_BEFORE_WARN,
    G_AFTER_WARN,
    G_BEFORE_ERR,
    G_AFTER_ERR,
    G_REPLACE,
} g_timings_t;

#endif /* !ADDONS_H_ */
