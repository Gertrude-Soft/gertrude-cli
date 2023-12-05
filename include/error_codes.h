/*
** EPITECH PROJECT, 2023
** gertrude-cli
** File description:
** error_codes
*/

#ifndef ERROR_CODES_H_
    #define ERROR_CODES_H_
    #include "text_mod.h"
    #define ERROR_WIDTH 80 // Even number recommended
    #define GERERR RED
    #define GERWARN MAGENTA

    #define VARWARN 21
    #define VARERR 42
    #define DIRERR 63

    #define ERR21 "** Variable affectation without value. **"
    #define BERR21 "Variable has been defaulted to empty \\."
    #define ERR42 "** Variable or positional argument missing. **"
    #define BERR42 "Gertrude no understand, Exited with crash."
    #define ERR63 "** No directory given as argument. **"
    #define BERR63 "Gertrude no understand, Exited with crash."

#endif
