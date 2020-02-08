//
// Created by Suliman Alsaid on 2/5/20.
//

#ifndef GAMEBOY_CPU_H
#define GAMEBOY_CPU_H

#include <string>

typedef unsigned char flag;
typedef unsigned char byte;
typedef unsigned short doubleByte;

const flag ZEROflag = 0b10000000;
const flag Nflag = 0b01000000;
const flag Hflag = 0b00100000;
const flag Cflag = 0b00010000;

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

    void setFlag(flag f);
    void clearFlag(flag f);


public:
    explicit CPU(std::string game);


    void loop();


    byte dec(byte regist);
    byte flip(byte regist);
    void write(doubleByte regist, byte value);

    doubleByte nn(doubleByte PC);

    void add(doubleByte& regist1, doubleByte regist2);
};


#endif //GAMEBOY_CPU_H
