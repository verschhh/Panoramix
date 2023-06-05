/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** init_struct.c
*/

#include "panoramix.h"

int end_struct(villager_t **villager, int nb_vil)
{
    for (int i = 0; i < nb_vil; i++) {
        free(villager[i]);
    }
    free(villager);
    return 0;
}

villager_t *init_villager(int nb_fight, int nb_vil, druid_t **druid)
{
    villager_t *villager = malloc(sizeof(villager_t));

    villager->nb_vil = nb_vil;
    villager->nb_fight = nb_fight;
    villager->druid = *druid;
    pthread_mutex_init(&villager->mutex, NULL);
    return (villager);
}

druid_t *init_druid(int pot_use, int nb_refill)
{
    druid_t *druid = malloc(sizeof(druid_t));

    druid->pot_use = pot_use;
    druid->pot_size = pot_use;
    druid->nb_refill = nb_refill;
    return (druid);
}

central_t *init_central(int pot_use, int nb_fight, int nb_refill, int nb_vil)
{
    central_t *central = malloc(sizeof(central_t));
    VIL = malloc(sizeof(villager_t *) * nb_vil);
    druid_t *druid = init_druid(pot_use, nb_refill);

    central->druid = druid;
    printf("Druid: I'm ready... but sleepy...\n");
    sem_init(&central->druid->call, 0, 0);
    sem_init(&central->druid->refill, 0, 1);
    pthread_mutex_init(&central->druid->mutex, NULL);
    for (int i = 0; i < nb_vil; i++)
        VIL[i] = init_villager(nb_fight, nb_vil - i, &central->druid);
    return (central);
}
