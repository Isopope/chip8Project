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

int jp1nnn(struct Processeur *cpu,uint16_t adresse);

int ret00ee(struct Processeur *cpu);

int se3xkk(struct Processeur *cpu, uint8_t x, uint8_t kk);

int call2nnn(struct Processeur *cpu, uint16_t addr);

int sne4xkk(struct Processeur *cpu, uint8_t x, uint8_t kk);

int se5xy0(struct Processeur *cpu, uint8_t x, uint8_t y);

int ld6xkk(struct Processeur *cpu, uint8_t x, uint8_t kk);

int add7xkk(struct Processeur *cpu, uint8_t x, uint8_t kk);

int ld8xy0(struct Processeur *cpu, uint8_t x, uint8_t y);

int or8xy1(struct Processeur *cpu, uint8_t x, uint8_t y);

int and8xy2(struct Processeur *cpu, uint8_t x, uint8_t y);

int xor8xy3(struct Processeur *cpu, uint8_t x, uint8_t y);

int add8xy4(struct Processeur *cpu, uint8_t x, uint8_t y);

int sub8xy5(struct Processeur *cpu, uint8_t x, uint8_t y);

int shr8xy6(struct Processeur *cpu, uint8_t x, uint8_t y);

int subn8xy7(struct Processeur *cpu, uint8_t x, uint8_t y);

int shl8xye(struct Processeur *cpu, uint8_t x, uint8_t y);

int sne9xy0(struct Processeur *cpu, uint8_t x, uint8_t y);

int ldannn(struct Processeur *cpu, uint16_t nnn);

int jpbnnn(struct Processeur *cpu,uint8_t x,uint8_t y, uint16_t nnn);

int rndcxkk(struct Processeur *cpu, uint8_t x, uint8_t kk);

int ldfx07(struct Processeur *cpu,uint8_t x);

int ldfx15(struct Processeur *cpu,uint8_t x);

int ldfx18(struct Machine *cp8,uint8_t x);

int addfx1e(struct Processeur *cpu,uint8_t x);

int ldfx29(struct Processeur *cpu,uint8_t x);

int ldfx33(struct Processeur *cpu, uint8_t x);

int ldfx55(struct Processeur *cpu,uint8_t x);

int ldfx65(struct Processeur *cpu, uint8_t x);

void ldfx0a(struct Machine *cp8,uint8_t x);

void skpex9e(struct Machine *cp8,uint8_t x);

void sknpexa1(struct Machine *cp8,uint8_t x);

int drwdxyn(struct Machine *cp8, uint8_t x, uint8_t y, uint8_t n);


void executer_instruction(struct Machine *cp8);





#endif
