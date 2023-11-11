/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-laurent.gonzalez
** File description:
** places_from_int_to_base
*/

int places_from_int_to_base(int number, int base)
{
    int places = 0;

    if (number == 0) {
        return 1;
    }
    while (number > 0) {
        number /= base;
        places++;
    }
    return places;
}
