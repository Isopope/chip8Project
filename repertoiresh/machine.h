#ifndef MACHINE_H
#define MACHINE_H
#include"processeur.h"
#include"display/display.h"
#include"display/sprite.h"
#include"keyboard/keyboard.h"
#include"speaker/speaker.h"
#include<SDL2/SDL.h>
struct Machine {
    struct Processeur *cpu;
    struct Memoire *ram;
    struct Display *display;
    struct Keyboard *keyboard;
    struct Speaker *speaker;
};

struct Machine *initialiser_machine();

void liberer_machine(struct Machine *cp8);

void machine_loop(struct Machine *cp8);

void charger_font(struct Machine *cp8);





#endif
