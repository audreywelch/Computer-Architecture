#include "cpu.h"

#define DATA_LEN 6

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
void cpu_load(struct cpu *cpu)
{
  char data[DATA_LEN] = {
    // From print8.ls8
    0b10000010, // LDI R0,8
    0b00000000,
    0b00001000,
    0b01000111, // PRN R0
    0b00000000,
    0b00000001  // HLT
  };

  int address = 0;

  for (int i = 0; i < DATA_LEN; i++) {
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

void cpu_ram_read(struct cpu *cpu_to_read) {

}

void cpu_ram_write(struct cpu *cpu_to_be_written_to, char *data) {

}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op) {
    case ALU_MUL:
      // TODO
      break;

    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction

  unsigned char pc = cpu->pc;

  while (running) {
    
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    unsigned char ir = cpu->ram[pc];

    // 2. Figure out how many operands this next instruction requires
    

    // 3. Get the appropriate value(s) of the operands following this instruction
    unsigned char operandA = cpu_ram_read(cpu->ram[pc + 1]);
    unsigned char operandB = cpu_ram_read(cpu->ram[pc + 2]);

    // 4. switch() over it to decide on a course of action.
    // 5. Do whatever the instruction should do according to the spec.
    // 6. Move the PC to the next instruction.
    switch (operandA) {
      
      case HLT:

        // Halt the CPU & exit the emulator
        running = 0;

        // This is a _-byte instruction
        // pc += _;
        break;

      case LDI:

        // Set the value of a register to an integer

        break;

      case PRN:

        // Print numeric value stored in the given register
        // Print to the console the decimal integer value that is stored in the given register

        break;

      // Handle unknown instructions
      default:
        printf("Unknown instruction %02x at address %02x\n", ir, pc);
        exit(1);
    }
  }
}

/**
 * Initialize a CPU struct
 */

// Takes a pointer to a struct cpu and initializes it as necessary
void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers
  cpu->pc = 0;

  memset(cpu->ir, 0, sizeof(cpu->ir));
  memset(cpu->ram, 0, sizeof(cpu->ram));

}
