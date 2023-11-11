/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-LAURENT.GONZALEZ
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
