#include"repertoiresh/machine.h"
struct Machine *initialiser_machine(){
    struct Machine *cp8=malloc(sizeof(struct Machine));
    cp8->cpu=initialiser_processeur();
    cp8->ram=cp8->cpu->ram;
    cp8->display=malloc(sizeof(struct Display));
    cp8->display = malloc(sizeof(struct Display));
    if (Display_init(cp8->display, 10) != 0) {
        fprintf(stderr, "Erreur : Impossible d'initialiser l'affichage.\n");
        liberer_processeur(cp8->cpu);
        Display_destroy (cp8->display);
        free(cp8);
        return NULL;
    }
    cp8->keyboard=malloc(sizeof(struct Keyboard));
    Keyboard_init(cp8->keyboard);
    cp8->speaker=malloc(sizeof(struct Speaker));
    Speaker_init(cp8->speaker);
    return cp8;

}

void liberer_machine(struct Machine *cp8){
    liberer_processeur(cp8->cpu);
    Display_destroy(cp8->display);
    Keyboard_destroy(cp8->keyboard);
    Speaker_destroy(cp8->speaker);
    free(cp8);

}

void machine_loop(struct Machine *cp8){

        int arret=0;
        while(!arret){
            executer_instruction(cp8);
            SDL_Event event;
            while(SDL_PollEvent(&event)!=0){
                if(event.type==SDL_QUIT){
                    arret=1;
                }
            }
            Display_update(cp8->display);
        }
       liberer_machine(cp8);
    }


void charger_font(struct Machine *cp8){
    uint8_t font_data[] = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80, // F

    };

    for (uint8_t i = 0; i < sizeof(font_data); i++)
    {
        cp8->ram->memoire[0x0+i]=font_data[i];
    }
}
