/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** fight.c
*/

#include "panoramix.h"

void print_fight(villager_t *vil)
{
    char *str = "Take that roman scum! Only";
    printf("Villager %d: %s %d left.\n", vil->nb_vil - 1, str, vil->nb_fight);
    return;
}

void print_potion(villager_t *vil)
{
    int nvil = vil->nb_vil - 1;
    int pot = vil->druid->pot_use;
    char *str = "I need a drink...";
    printf("Villager %d: %s I see %d servings left.\n", nvil, str, pot);
    return;
}

int call_or_drink(villager_t *villager)
{
    if (villager->druid->pot_use == 0 && villager->druid->nb_refill > 0) {
        print_potion(villager);
        printf("Villager %d: Hey Pano wake up!", villager->nb_vil - 1);
        printf(" We need more potion.\n");
        pthread_mutex_lock(&villager->mutex);
        sem_post(&villager->druid->call);
        sem_wait(&villager->druid->refill);
        pthread_mutex_unlock(&villager->mutex);
        sleep(0.1);
        return 0;
    }
    return 1;
}

int fight(villager_t *villager)
{
    while (villager->nb_fight > 0) {
        pthread_mutex_lock(&villager->druid->mutex);
        if (call_or_drink(villager) == 1)
            print_potion(villager);
        villager->druid->pot_use--;
        villager->nb_fight--;
        print_fight(villager);
        pthread_mutex_unlock(&villager->druid->mutex);
    }
    return 0;
}
