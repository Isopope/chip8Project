#include"repertoiresh/machine.h"
#include <SDL2/SDL.h>
#include"display/display.h"
#include"display/sprite.h"
#include"keyboard/keyboard.h"
#include"speaker/speaker.h"
int main(int argc, char *argv[])
{
if (argc != 2) {
        fprintf(stderr, "Unexpected number of arguments.\n");
        fprintf(stderr, "Usage: emulator <ROM.ch8>\n");
        return 1;
    }
    struct Machine *cp8=initialiser_machine();
    charger_rom(cp8->ram,argv[1]);
    machine_loop(cp8);
    liberer_machine(cp8);
    return 0;
}
