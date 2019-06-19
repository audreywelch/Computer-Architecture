#include <stdio.h>
#include "cpu.h"

/**
 * Main
 */
// argc = argument count
// argv = array of strings that hold the individual arguments, starting with the command name itself
int main(int argc, char *argv[])
{
  struct cpu cpu;

  cpu_init(&cpu);
  cpu_load(&cpu);
  cpu_run(&cpu);

  return 0;
}

/*
type into command line:
./ls8 examples/mult.ls8

Values of `argv` will be:

argv[0] == "./ls8"
argv[1] == "examples/mult.ls8"

 */