//
// Created by Suliman Alsaid on 2/5/20.
//

#ifndef GAMEBOY_CPU_H
#define GAMEBOY_CPU_H

#include <string>

typedef unsigned char byte;
typedef unsigned short doubleByte;

class CPU {


    byte memory[65536];


    union {
        struct {
            byte F;
            byte A;

        };
        doubleByte AF;
    };

    union {
        struct {
            byte C;
            byte B;

        };
        doubleByte BC;
    };

    union {
        struct {
            byte E;
            byte D;

        };
        doubleByte DE;
    };

    union {
        struct {
            byte L;
            byte H;

        };
        doubleByte HL;
    };

    doubleByte SP;
    doubleByte PC;

public:
    explicit CPU(std::string game);




};


#endif //GAMEBOY_CPU_H
