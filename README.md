# Holberton Monty Bytecode Interpreter

This repository contains the source code for a Monty bytecode interpreter, a project developed as part of the Holberton School curriculum. The interpreter is written in C and is designed to execute Monty bytecode files.

## Files

The repository contains the following files:

- `freedom.c`: This file contains the function `free_stack` which is used to free a doubly linked list.
- `main.c`: This is the main file of the project. It contains the `main` function which opens a Monty bytecode file, reads its instructions line by line, and executes them.
- `monty.h`: This is the header file for the project. It contains all the function prototypes and the definitions of the `struct` types used in the project.
- `opcodes_alpha.c`: This file contains the implementation of various opcode functions such as `pall_monty`, `push_monty`, `pint_monty`, `nop_monty`, and `pop_monty`.
- `opcodes_bravo.c`: This file contains the implementation of various opcode functions such as `swap_monty`, `add_monty`, `sub_monty`, `div_monty`, and `mul_monty`.
- `opcodes_charlie.c`: This file contains the implementation of various opcode functions such as `mod_monty`, `pchar_monty`, `pstr_monty`, `rotl_monty`, and `rotr_monty`.
- `theWay.c`: This file contains the function `op_fun_res` which matches the opcode read from the bytecode file to the corresponding function and executes it.

## Usage

To use the Monty bytecode interpreter, compile all the `.c` files in the repository and run the resulting executable with the path to a Monty bytecode file as an argument.

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
./monty bytecode.m
