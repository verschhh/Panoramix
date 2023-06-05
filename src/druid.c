/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** druid.c
*/

#include "panoramix.h"

void print_druid(druid_t *druid)
{
    char *str1 = "Druid: Ah! Yes, yes, I'm awake! Working on it! ";
    char *str2 = "Beware I can only make";
    char *str3 = " more refills after this one.\n";

    printf("%s%s%d%s", str1, str2, druid->nb_refill, str3);
    return;
}

void *druid_tr(void *arg)
{
    druid_t *druid = (druid_t *)arg;
    while (1) {
        sem_wait(&druid->call);
        if (druid->nb_refill > 0) {
            druid->nb_refill--;
            print_druid(druid);
            druid->pot_use = druid->pot_size;
        }
        if (druid->nb_refill == 0) {
            printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
            sem_post(&druid->refill);
            return NULL;
        }
        sem_post(&druid->refill);
    }
    return NULL;
}
