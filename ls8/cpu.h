#ifndef _CPU_H_
#define _CPU_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Holds all information about the CPU
// Type for a single unsigned byte is unsigned char
struct cpu {
  // TODO
  // PC: Program Counter
  unsigned char pc;

  // flag register
  unsigned char flag;

  // registers (array): Instruction Register
  unsigned char registers[8];

  // ram (array)
  unsigned char ram[256];

};

// ALU operations
enum alu_op {
	ALU_MUL
	// Add more here
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI  0b10000010
#define PRN  0b01000111
// TODO: more instructions here. These can be used in cpu_run().
#define HLT  0b00000001

// Function declarations

extern void cpu_load(char *filename, struct cpu *cpu);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
