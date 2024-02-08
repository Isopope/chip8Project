#include "repertoiresh/memoire.h"
#include <stdlib.h>

struct Memoire *initialiser_memoire() {
    struct Memoire *ram = malloc(sizeof(struct Memoire));
    for (int i = 0; i < TAILLE_MEMOIRE; i++) {
        ram->memoire[i] = 0;
    }
    return ram;
}

void liberer_memoire(struct Memoire *ram) {
    free(ram->memoire);
    free(ram);
}

uint8_t lecture_memoire(struct Memoire *ram, uint16_t adresse) {
    if (adresse < 0 || adresse >= TAILLE_MEMOIRE) {
        return ERREUR;
    }
    return ram->memoire[adresse];
}

int ecriture_memoire(struct Memoire *ram, uint16_t adresse, uint8_t data) {
    if (adresse < 0 || adresse >= TAILLE_MEMOIRE) {
        return ERREUR;
    }
    ram->memoire[adresse] = data;
    return SUCCESS;
}

int charger_rom(struct Memoire *ram, const char *nom_fichier) {
    FILE *fichier_rom = fopen(nom_fichier, "rb");
    if (fichier_rom == NULL) {
        fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier ROM.\n");
        return ERREUR;
    }

    fseek(fichier_rom, 0, SEEK_END);
    long taille_rom = ftell(fichier_rom);
    rewind(fichier_rom);

    if (taille_rom > (TAILLE_MEMOIRE - ADRESSE_DEBUT)) {
        fprintf(stderr, "Erreur : Le fichier ROM est trop volumineux pour la mémoire Chip-8.\n");
        fclose(fichier_rom);
        return ERREUR;
    }

    fread(ram->memoire + ADRESSE_DEBUT, 1, taille_rom, fichier_rom);
    fclose(fichier_rom);

    return SUCCESS;
}
