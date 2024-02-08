#ifndef PROCESSEUR_H
#define PROCESSEUR_H
#include"memoire.h"
#include"machine.h"
#define TAILLE_REGISTRE 16
#define TAILLE_PILE 16

struct Processeur {
    uint8_t V[TAILLE_REGISTRE];
    uint16_t I;
    uint8_t DT; //DELAY TIMER;
    uint8_t ST ;//SOUND TIMER;
    uint16_t PC;
    uint16_t stack[TAILLE_PILE];
    uint8_t SP;
    struct Memoire *ram;
};

struct Processeur *initialiser_processeur();

void liberer_processeur(struct Processeur *cpu);

void executer_instruction(struct Machine *cp8);





#endif
