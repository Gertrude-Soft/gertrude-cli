/*
** GERTRUDE PROJECT, 2023
** Gertrude-CLI
** File description:
** Configuration File
*/

#ifndef GER_CONF_H_
    #define GER_CONF_H_

    #define CONFDIR "/opt/gertrude-cli/include/ger_conf.h"
    #include <stdbool.h>

/* DO NOT MODIFY ABOVE THIS LINE */

// This defines the width of the error messages gertrude throws in
// the terminal (using an even number is much recommended) - default 80
    #define ERROR_WIDTH 80

// Rules like all, re, clean, fclean get affected automatically - default true
// Note, the gertrude rule will not be affected by this option
    #define REMARKABLE true

// This editor will be used when changing this configuration file
// (from gertrude config command) - default "nano"
    #define EDITOR "nano"

// If REMARKABLE is true > The clean rule will also remove files that match
// the specified pattern - default "vgcore*"
    #define EXTRA "vgcore*"

// This defines whether to include a header or not in the Makefile - default true
    #define HEADER true

// This defines whether your rules are added to a .PHONY at the end of the
// generated Makefile (recommended true) - default true
    #define AUTO_PHONY true

// This is the default header that will be used in the Makefile, you can
// modify it freely but be careful with the formatting.
    #define DEFAULT_HEADER "/opt/gertrude-cli/gertrude_prebuilt_mkf/default_header"

// This is the standard EPITECH header, modify as needed if you are
// an EPITECH student who knows what to do.
    #define EPIHEADER "/opt/gertrude-cli/gertrude_prebuilt_mkf/epiheader"

/* DO NOT MODIFY BELOW THIS LINE */

    #define REM_ALL "all:\tcompile\tclean\tgertrude\n\n"
    #define REM_COMPILE "compile:\n\n"
    #define REM_CLEAN "clean:\n\trm -f *.o\n\n"
    #define REM_FCLEAN "fclean:\tclean\n\trm -f $(NAME)\n\n"
    #define REM_RE "re:\tfclean\tall\n\n"

    #define REM_GERTRUDE "gertrude:\n\t@echo -e \"\\n\\n\\033[3mGertrude-CLI - Makefile creation tool\\033[0m\\n\"\n\n"

#endif /* !GER_CONF_H_ */
