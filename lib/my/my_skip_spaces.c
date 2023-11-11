/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** my_skip_spaces
*/

void skip_spaces(const char *format, int *i)
{
    *i = *i + 1;
    while (format[*i] == ' ') {
        *i = *i + 1;
    }
    *i = *i - 1;
}
