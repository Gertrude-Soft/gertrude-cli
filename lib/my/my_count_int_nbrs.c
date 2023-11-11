/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** count_int_nbrs
*/

int count_int_nbrs(int i)
{
    int c = 1;

    while (i / 10 != 0) {
        i = i / 10;
        c++;
    }
    return (c);
}
