#include <stdlib.h>

#define MEMORY_MAX (1 << 16)

enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /* program counter */
    R_COND,
    R_COUNT
};

enum {
    OP_BR = 0, /* branch */
    OP_ADD,    /* add  */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum {
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2, /* N */
};

uint16_t memory[MEMORY_MAX];  /* 65536 locations */
uint16_t reg[R_COUNT];

int main(int argc, char **argv){
    // TODO: Load Arguments
    if (argc < 2) {
        /* show usage string */
        printf("lc3 [image-file1] ...\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 1; j < argc; ++j) {
        if (!read_image(argv[j])) {
            printf("failed to load image: %s\n", argv[j]);
            exit(1);
        }
    }
    // TODO: Setup

    /* since exactly one condition flag should be set at any given time, set the Z flag */
    reg[R_COND] = FL_ZRO;

    /* set the PC to starting position */
    /* 0x3000 is the default */
    enum { PC_START = 0x3000 };
    reg[R_PC] = PC_START;

    int running = 1;
    while(running) {
        /* Fetch next instruction */
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch (op) {
            case OP_ADD:
                // TODO: {ADD}
                break;
            case OP_AND:
                // TODO: {AND}
                break;
            case OP_NOT:
                // TODO: {NOT}
                break;
            case OP_BR:
                // TODO: {BR}
                break;
            case OP_JMP:
                // TODO: {JMP}
                break;
            case OP_JSR:
                // TODO: {JSR}
                break;
            case OP_LD:
                // TODO: {LD}
                break;
            case OP_LDI:
                // TODO: {LDI}
                break;
            case OP_LDR:
                // TODO: {LDR}
                break;
            case OP_LEA:
                // TODO: {LEA}
                break;
            case OP_ST:
                // TODO: {ST}
                break;
            case OP_STI:
                // TODO: {STI}
                break;
            case OP_STR:
                // TODO: {STR}
                break;
            case OP_TRAP:
                // TODO: {TRAP}
                break;
            case OP_RES:
            case OP_RTI:
            default:
                // TODO: {BAD OPCODE}
                break;
        }
    }

    // TODO: SHUTDOWN
}