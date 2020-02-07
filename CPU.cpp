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

}
