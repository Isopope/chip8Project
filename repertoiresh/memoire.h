#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include"erreur.h"
#define TAILLE_MEMOIRE 4096
#define ADRESSE_DEBUT 0x200

struct Memoire {
    uint8_t memoire[TAILLE_MEMOIRE];
};

struct Memoire* initialiser_memoire();

void liberer_memoire(struct Memoire *ram);

uint8_t lecture_memoire(struct Memoire *ram,uint16_t adresse);

int ecriture_memoire(struct Memoire *ram,uint16_t adresse, uint8_t data);

int charger_rom(struct Memoire *ram, const char *nom_fichier);

#endif /* MEMORY_H */
