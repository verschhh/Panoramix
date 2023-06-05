/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** main.c
*/

#include "panoramix.h"

int print_usage(int arg)
{
    if (arg == 1) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_use>");
        printf("<nb_fight> <nb_refill>\nValues must be >0.\n");
    } else {
        printf("USAGE: ./panoramix <nb_villagers>");
        printf("<pot_use> <nb_fight> <nb_refill>\n");
    }
    return (84);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        return (print_usage(0));
    }
    if (argc != 5)
        return (print_usage(0));
    for (int i = 1; i < argc; i++) {
        if (atoi(argv[i]) <= 0)
            return (print_usage(1));
    }
    body(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    return (0);
}
