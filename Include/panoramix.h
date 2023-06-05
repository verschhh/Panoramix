/*
** EPITECH PROJECT, 2022
** Semestre4
** File description:
** panoramix.h
*/

#ifndef PANORAMIX_H_
#define PANORAMIX_H_

#include <stdio.h>
#include <stdlib.h>
#include "semaphore.h"
#include "pthread.h"
#include "fcntl.h"
#include "unistd.h"
#include <sys/wait.h>
#define VIL central->villager

typedef struct druid_s {
    int pot_use;
    int pot_size;
    int nb_refill;
    sem_t call;
    sem_t refill;
    pthread_mutex_t mutex;
} druid_t;

typedef struct villager_s {
    int nb_fight;
    int nb_vil;
    druid_t *druid;
    pthread_mutex_t mutex;
} villager_t;

typedef struct central_s {
    int n_vil;
    villager_t **villager;
    druid_t *druid;
} central_t;

central_t *init_central(int pot_use, int nb_fight, int nb_refill, int nb_vil);
int body(int nb_vil, int pot_use, int nb_fight, int nb_refill);
int end_struct(villager_t **villager, int nb_vil);
void *villager_tr();
void *druid_tr(void *arg);
int fight(villager_t *villager);

#endif /* !PANORAMIX_H_ */
