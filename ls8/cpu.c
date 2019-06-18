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

// Helper function to read a value from the specified index in RAM
// Returns the read value
// index = memory address register (mar)
unsigned char cpu_ram_read(struct cpu *cpu, unsigned char index) {
  return cpu->ram[index];
}

// Helper function to write a value to the specified index in RAM
// value = memory data register (mdr) - value to write to
void cpu_ram_write(struct cpu *cpu, unsigned char index, unsigned char value) {
  cpu->ram[index] = value;
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
    unsigned char ir = cpu_ram_read(cpu, cpu->pc);

    // 2. Figure out how many operands this next instruction requires
    // This determines how much to add to the PC - # of operands + 1
    int add_to_pc = (ir >> 6) + 1;
    
    // 3. Get the appropriate value(s) of the operands following this instruction
    unsigned char operandA = cpu_ram_read(cpu, cpu->ram[pc + 1]);
    unsigned char operandB = cpu_ram_read(cpu, cpu->ram[pc + 2]);

    // 4. switch() over it to decide on a course of action.
    // 5. Do whatever the instruction should do according to the spec.
    // 6. Move the PC to the next instruction.
    switch (ir) {
      
      case HLT:

        // Halt the CPU & exit the emulator
        running = 0;

        // This is a _-byte instruction
        pc += add_to_pc;
        break;

      case LDI:

        // Set the value of a register to an integer
        cpu_ram_write(cpu, cpu->registers[operandA], cpu->registers[operandB]);

        pc += add_to_pc;

        break;

      case PRN:

        // Print numeric value stored in the given register
        unsigned char value = cpu_ram_read(cpu, operandA);

        // Print to the console the decimal integer value that is stored in the given register
        printf("%d\n", cpu->registers[value]);

        pc += add_to_pc;

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
  // TODO: Initialize the PC and other special registers, clearing them to 0
  cpu->pc = 0;
  cpu->flag = 0;

  memset(cpu->registers, 0, sizeof(cpu->registers));
  memset(cpu->ram, 0, sizeof(cpu->ram));

  // Initialize SP (stack pointer)
  cpu->registers[7] = 0xF4;

  //cpu->registers[SP] = ADDR_EMPTY_STACK;
}
