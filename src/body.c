/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** body.c
*/

#include "panoramix.h"

int body(int nb_vil, int pot_use, int nb_fight, int nb_refill)
{
    central_t *central = init_central(pot_use, nb_fight, nb_refill, nb_vil);
    pthread_t *druid = malloc(sizeof(pthread_t));
    pthread_t *thread = malloc(sizeof(pthread_t) * nb_vil);

    pthread_create(druid, NULL, &druid_tr, central->druid);
    for (int i = 0; i < nb_vil; i++) {
        if (pthread_create(&thread[i], NULL, &villager_tr, VIL[i]) != 0)
            return (84);
    }
    for (int i = 0; i < nb_vil; i++) {
        pthread_join(thread[i], NULL);
    }
    return (end_struct(central->villager, nb_vil));
}
