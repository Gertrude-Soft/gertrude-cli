/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday05-laurent.gonzalez
** File description:
** my_compute_power_rec
*/

int mul_check_overflow(int nb1, int nb2)
{
    if (nb1 == 0 || nb2 == 0) {
        return (0);
    }
    if (nb1 > 2147483647 / nb2) {
        return 0;
    }
    return (nb1 * nb2);
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p == 1) {
        return (nb);
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}
