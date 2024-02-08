#include"repertoiresh/processeur.h"
#include"repertoiresh/machine.h"
struct Processeur *initialiser_processeur(){
    struct Memoire *ram=initialiser_memoire();
    struct Processeur *cpu=malloc(sizeof(struct Processeur));
    cpu->I=0;
    cpu->DT=0;
    cpu->PC=ADRESSE_DEBUT;
    cpu->ST=0;
    cpu->SP=0;
    unsigned int uiBoucle=0;
    for(uiBoucle=0;uiBoucle<TAILLE_REGISTRE;uiBoucle++){
        cpu->V[uiBoucle]=0;
    }
    for(uiBoucle=0;uiBoucle<TAILLE_PILE;uiBoucle++){
        cpu->stack[uiBoucle]=0;
    }
    cpu->ram=ram;
    return cpu;

}

void liberer_processeur(struct Processeur *cpu){
    liberer_memoire(cpu->ram);
    free(cpu);
}



int jp1nnn(struct Processeur *cpu,uint16_t adresse){
    if(cpu){
        cpu->PC=adresse;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ret00ee(struct Processeur *cpu){
    if (cpu->SP > 0) {
        cpu->SP--;
        cpu->PC = cpu->stack[cpu->SP];
        return SUCCESS;
    } else {
        return ERREUR;
    }

}

int se3xkk(struct Processeur *cpu, uint8_t x, uint8_t kk){
    if(cpu){
        if(cpu->V[x]==kk){
            cpu->PC+=2;
        }
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int call2nnn(struct Processeur *cpu, uint16_t addr) {
    if (cpu->SP < TAILLE_PILE) {
        cpu->stack[cpu->SP] = cpu->PC;
        cpu->SP++;
        cpu->PC = addr;
        return SUCCESS;
    } else {
        return ERREUR;
    }
}

int sne4xkk(struct Processeur *cpu, uint8_t x, uint8_t kk){
    if(cpu){
        if(cpu->V[x]!=kk){
            cpu->PC+=2;
        }
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int se5xy0(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        if(cpu->V[x]==cpu->V[y]){
            cpu->PC+=2;
        }
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ld6xkk(struct Processeur *cpu, uint8_t x, uint8_t kk){
    if(cpu){
        cpu->V[x]=kk;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int add7xkk(struct Processeur *cpu, uint8_t x, uint8_t kk){
    if(cpu){
        cpu->V[x]=cpu->V[x]+kk;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ld8xy0(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        cpu->V[x]=cpu->V[y];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int or8xy1(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        cpu->V[x]|=cpu->V[y];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int and8xy2(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        cpu->V[x]&=cpu->V[y];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int xor8xy3(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        cpu->V[x]^=cpu->V[y];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int add8xy4(struct Processeur *cpu, uint8_t x, uint8_t y){
    // a revoir plus tard
    if(cpu){
        if((cpu->V[x]+cpu->V[y])>0xFF){
        cpu->V[0xF]=1;
    }else{
        cpu->V[0xF]=0;
    }
    cpu->V[x]+=cpu->V[y];
    return SUCCESS;
    }else{
        return ERREUR;
    }
}

int sub8xy5(struct Processeur *cpu, uint8_t x, uint8_t y){
    // a revoir plus tard
    if(cpu){
        if((cpu->V[x]<cpu->V[y])){
            cpu->V[0xF]=0;
        }else{
            cpu->V[0xF]=1;
        }
        cpu->V[x]-=cpu->V[y];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int shr8xy6(struct Processeur *cpu, uint8_t x, uint8_t y){
    // a revoir plus tard
    if(cpu){
        cpu->V[0xF]=(cpu->V[x]&0x01);
        cpu->V[x]=(cpu->V[x]>>1);
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int subn8xy7(struct Processeur *cpu, uint8_t x, uint8_t y){
    // a revoir plus tard
    if(cpu){
        if(cpu->V[y]<cpu->V[x]){
            cpu->V[0xF]=0;
        }else{
            cpu->V[0xF]=1;
        }
        cpu->V[x]=cpu->V[y]-cpu->V[x];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int shl8xye(struct Processeur *cpu, uint8_t x, uint8_t y){
    // a revoir plus tard
    if(cpu){
        cpu->V[0xF]=(cpu->V[x]>>7);
        cpu->V[x]=(cpu->V[x]<<1);
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int sne9xy0(struct Processeur *cpu, uint8_t x, uint8_t y){
    if(cpu){
        if(cpu->V[x]!=cpu->V[y]){
            cpu->PC+=2;
        }
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldannn(struct Processeur *cpu, uint16_t nnn){
    if(cpu){
        cpu->I=nnn;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int jpbnnn(struct Processeur *cpu,uint8_t x,uint8_t y, uint16_t nnn){
    if(cpu){
        //cpu->PC=nnn+cpu->V[0];
        cpu->PC=(x<<8)+(y<<4)+nnn+cpu->V[0];
        cpu->PC-=2;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int rndcxkk(struct Processeur *cpu, uint8_t x, uint8_t kk){
    if(cpu){
        cpu->V[x]=(rand()%0x100) & kk;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx07(struct Processeur *cpu,uint8_t x){
    if(cpu){
        cpu->V[x]=cpu->DT;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx15(struct Processeur *cpu,uint8_t x){
    if(cpu){
        cpu->DT=cpu->V[x];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx18(struct Machine *cp8,uint8_t x){
    if(cp8){
        cp8->cpu->ST=cp8->cpu->V[x];
        Speaker_on(cp8->speaker);

        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int addfx1e(struct Processeur *cpu,uint8_t x){
    if(cpu){
        cpu->I+=cpu->V[x];
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx29(struct Processeur *cpu,uint8_t x){
    if(cpu){
        cpu->I=cpu->V[x]*5;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx33(struct Processeur *cpu, uint8_t x){
    if(cpu){
        cpu->ram->memoire[cpu->I]=(cpu->V[x]-cpu->V[x]%100)/100;
        cpu->ram->memoire[cpu->I+1]=(cpu->V[x]/10)%10;
        cpu->ram->memoire[cpu->I+2]=cpu->V[x]%10;
        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx55(struct Processeur *cpu,uint8_t x){
    if(cpu){
        int uiBoucle=0;
        for(uiBoucle=0;uiBoucle<=x;uiBoucle++){
            cpu->ram->memoire[cpu->I+uiBoucle]=cpu->V[uiBoucle];
        }

        return SUCCESS;
    }else{
        return ERREUR;
    }
}

int ldfx65(struct Processeur *cpu, uint8_t x){
    if(cpu){
        int uiBoucle=0;
        for(uiBoucle=0;uiBoucle<=x;uiBoucle++){
            cpu->V[uiBoucle]=cpu->ram->memoire[cpu->I+uiBoucle];
        }

        return SUCCESS;
    }else{
        return ERREUR;
    }
}

void ldfx0a(struct Machine *cp8,uint8_t x){
    uint8_t key_pressed;
    Keyboard_wait(cp8->keyboard,&key_pressed);
    cp8->cpu->V[x]=key_pressed;


}

void skpex9e(struct Machine *cp8,uint8_t x){
    if(Keyboard_get(cp8->keyboard,cp8->cpu->V[x])==KEY_DOWN){
        cp8->cpu->PC+=2;
    }
}

void sknpexa1(struct Machine *cp8,uint8_t x){
    if(Keyboard_get(cp8->keyboard,cp8->cpu->V[x])==KEY_UP){
        cp8->cpu->PC+=2;
    }
}
int drwdxyn(struct Machine *cp8, uint8_t x, uint8_t y, uint8_t n) {
    uint8_t *spriteData=&(cp8->ram->memoire[cp8->cpu->I]);
    cp8->cpu->V[0xF]=0;
    struct Sprite sprite;
    Sprite_init(&sprite,n);
    int i=0;
    for(i=0;i<n;i++){
        Sprite_add(&sprite,spriteData[i]);
    }
    Display_DRW(cp8->display,&sprite,cp8->cpu->V[x],cp8->cpu->V[y],&(cp8->cpu->V[0xF]));
    Display_update(cp8->display);
    Sprite_destroy(&sprite);
    return SUCCESS;

}

void executer_instruction(struct Machine *cp8){
    struct Processeur *cpu=cp8->cpu;
    // Lire l'instruction depuis la mémoire
    uint16_t instruction = (cpu->ram->memoire[cpu->PC] << 8) | cpu->ram->memoire[cpu->PC + 1];

    // Incrémenter immédiatement le compteur de programme (PC)
    cpu->PC += 2;

    // Extraire les parties de l'instruction (opcodes et paramètres)
    uint8_t opcode = (instruction >> 12) & 0xF;
    uint16_t nnn = instruction & 0xFFF;
    uint8_t kk = instruction & 0xFF;
    uint8_t x = (instruction >> 8) & 0xF;
    uint8_t y = (instruction >> 4) & 0xF;
    uint8_t n = instruction & 0xF;

    switch (opcode) {
        case 0x0:
            switch (kk) {
                case 0xE0:
                    // CLS (Clear display)
                    Display_CLS (cp8->display);
                    break;

                case 0xEE:
                    // RET (Return from subroutine)
                    ret00ee(cpu);
                    break;

                default:

                    break;
            }
            break;

        case 0x1:
            // JP addr (Jump to location nnn)
            jp1nnn(cpu,nnn);
            break;

        case 0x2:
            // CALL addr (Call subroutine at nnn)
            call2nnn(cpu,nnn);

            break;

        case 0x3:
            // SE Vx, byte (Skip next instruction if Vx == kk)
            se3xkk(cpu,x,kk);
            break;

        case 0x4:
            // SNE Vx, byte (Skip next instruction if Vx != kk)
            sne4xkk(cpu,x,kk);
            break;

        case 0x5:
            // SE Vx, Vy (Skip next instruction if Vx == Vy)
            se5xy0(cpu,x,y);
            break;

        case 0x6:
            // LD Vx, byte (Set Vx = kk)
            ld6xkk(cpu,x,kk);
            break;

        case 0x7:
            // ADD Vx, byte (Set Vx = Vx + kk)
            add7xkk(cpu,x,kk);
            break;

        case 0x8:
            switch (n) {
                case 0x0:
                    // LD Vx, Vy (Set Vx = Vy)
                    ld8xy0(cpu,x,y);
                    break;

                case 0x1:
                    // OR Vx, Vy (Set Vx = Vx OR Vy)
                    or8xy1(cpu,x,y);
                    break;

                case 0x2:
                    // AND Vx, Vy (Set Vx = Vx AND Vy)
                    and8xy2(cpu,x,y);
                    break;

                case 0x3:
                    // XOR Vx, Vy (Set Vx = Vx XOR Vy)
                    xor8xy3(cpu,x,y);
                    break;

                case 0x4:
                    // ADD Vx, Vy (Set Vx = Vx + Vy, set VF = carry)
                    add8xy4(cpu,x,y);
                    break;

                case 0x5:
                    // SUB Vx, Vy (Set Vx = Vx - Vy, set VF = NOT borrow)
                    sub8xy5(cpu,x,y);
                    break;

                case 0x6:
                    // SHR Vx {, Vy} (Set Vx = Vx SHR 1)
                    shr8xy6(cpu,x,y);
                    break;

                case 0x7:
                    // SUBN Vx, Vy (Set Vx = Vy - Vx, set VF = NOT borrow)
                    subn8xy7(cpu,x,y);
                    break;

                case 0xE:
                    // SHL Vx {, Vy} (Set Vx = Vx SHL 1)
                    shl8xye(cpu,x,y);
                    break;

                default:
                    // Gestion des opcodes non pris en charge
                    break;
            }
            break;

        case 0x9:
            // SNE Vx, Vy (Skip next instruction if Vx != Vy)
            sne9xy0(cpu,x,y);
            break;

        case 0xA:
            // LD I, addr (Set I = nnn)
            ldannn(cpu,nnn);
            break;

        case 0xB:
            // JP V0, addr (Jump to location nnn + V0)
            jpbnnn(cpu,x,y,nnn);
            break;

        case 0xC:
            // RND Vx, byte (Set Vx = random byte AND kk)
            rndcxkk(cpu,x,kk);
            break;

        case 0xD:
            // DRW Vx, Vy, nibble (Display n-byte sprite at (Vx, Vy), set VF = collision)
            drwdxyn(cp8,x,y,n);
            break;

        case 0xE:
            switch (kk) {
                case 0x9E:
                    // SKP Vx (Skip next instruction if key with the value of Vx is pressed)
                    skpex9e(cp8,x);

                    break;

                case 0xA1:
                    // SKNP Vx (Skip next instruction if key with the value of Vx is not pressed)
                    sknpexa1(cp8,x);
                    break;

                default:
                    // Gestion des opcodes non pris en charge
                    // ...
                    break;
            }
            break;

        case 0xF:
            switch (kk) {
                case 0x07:
                    // LD Vx, DT (Set Vx = delay timer value)
                    ldfx07(cpu,x);
                    break;

                case 0x0A:
                    // LD Vx, K (Wait for a key press, store the value of the key in Vx)
                    ldfx0a(cp8,x);
                    break;

                case 0x15:
                    // LD DT, Vx (Set delay timer = Vx)
                    ldfx15(cpu,x);
                    break;

                case 0x18:
                    // LD ST, Vx (Set sound timer = Vx)
                    ldfx18(cp8,x);
                    break;

                case 0x1E:
                    // ADD I, Vx (Set I = I + Vx)
                    addfx1e(cpu,x);
                    break;

                case 0x29:
                    // LD F, Vx (Set I = location of sprite for digit Vx)
                    ldfx29(cpu,x);
                    break;

                case 0x33:
                    // LD B, Vx (Store BCD representation of Vx in memory locations I, I+1, and I+2)
                    ldfx33(cpu,x);
                    break;

                case 0x55:
                    // LD [I], Vx (Store registers V0 through Vx in memory starting at location I)
                    ldfx55(cpu,x);
                    break;

                case 0x65:
                    // LD Vx, [I] (Read registers V0 through Vx from memory starting at location I)
                    ldfx65(cpu,x);
                    break;

                default:

                    break;
            }
            break;

        default:

            break;
    }

}

