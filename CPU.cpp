//
// Created by Suliman Alsaid on 2/5/20.
//

#include "CPU.h"
#include <cstdio>

CPU::CPU(std::string game) {
    memset(memory, 0, sizeof(memory));
    FILE *rom = fopen(game.c_str(), "rb");
    fread(memory, sizeof(byte), 32768, rom);
    fclose(rom);

    AF=0x01B0;
    BC=0x0013;
    DE=0x00D8;
    HL=0x014D;
    SP=0xFFFE;
    PC=0x0100;

    loop();
}

void CPU::loop() {
    while(true) {

        byte opcode = memory[PC++];
        switch (opcode) {
            case 0x00:
                break;
            case 0xC3:
                PC = nn(PC);
                break;
            case 0x48:
                C = B;
                break;
            case 0x49:
                C = C;
                break;
            case 0x4A:
                C = D;
                break;
            case 0x2F:
                A = flip(A);
                break;
            case 0x0B:
                BC--;
                break;
            case 0x25:
                H = dec(H);
                break;
            case 0x1D:
                E = dec(E);
                break;
            case 0x22:
                write(HL++, A);
                break;
            case 0x19:
                add(HL, DE);
                break;
            case 0x0E:
                C = memory[PC++];
                break;

        }
    }

}

void CPU::setFlag(flag f) {
    F |= f;

}

void CPU::clearFlag(flag f) {
    F &= (~f);

}

byte CPU::dec(byte regist) {
   if(regist & 0x0F) clearFlag(Hflag);
   else setFlag(Hflag);

   regist--;
   setFlag(Nflag);

    if(regist == 0)
        setFlag(ZEROflag);
    else
        clearFlag(ZEROflag);


    return regist;

}

byte CPU::flip(byte regist) {
    setFlag(Nflag);
    setFlag(Hflag);
    return (~regist);
}

void CPU::write(doubleByte regist, byte value) {
    memory[regist] = value;
}

doubleByte CPU::nn(doubleByte PC) {
    return memory[PC] << 8 | memory[PC + 1];
}

void CPU::add(doubleByte &regist1, doubleByte regist2) {
    unsigned long result = regist1+regist2;

    if(result & 0xffff0000) setFlag(Cflag);
    else clearFlag(Cflag);

    regist1 = static_cast<doubleByte>(result & 0xFFFF);
    if(((regist1 & 0x0f) + (regist2 & 0x0f)) > 0x0f) setFlag(Hflag);
    else clearFlag(Hflag);

    clearFlag(Nflag);

}





