/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** villager.c
*/

#include "panoramix.h"

void *villager_tr(void *arg)
{
    villager_t *villager = (villager_t *)arg;
    printf("Villager %d: Going into battle!\n", villager->nb_vil - 1);
    fight(villager);
    printf("Villager %d: I'm going to sleep now.\n", villager->nb_vil - 1);
    pthread_exit(NULL);
}
