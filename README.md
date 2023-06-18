# Holberton Monty Bytecode Interpreter

## Synopsis

This repository contains the source code for a Monty bytecode interpreter, a project developed as part of the Holberton School curriculum. The interpreter is written in C and is designed to execute Monty bytecode files.

## How Does It Work?

The interpreter reads Monty bytecode files line by line, identifies the opcode in each line, and executes the corresponding function.

## File & Function Descriptions

### Files

- `freedom.c`: Contains the function `free_stack` which is used to free a doubly linked list.
- `main.c`: The main file of the project. It contains the `main` function which opens a Monty bytecode file, reads its instructions line by line, and executes them.
- `monty.h`: The header file for the project. It contains all the function prototypes and the definitions of the `struct` types used in the project.
- `opcodes_alpha.c`: Contains the implementation of various opcode functions such as `pall_monty`, `push_monty`, `pint_monty`, `nop_monty`, and `pop_monty`.
- `opcodes_bravo.c`: Contains the implementation of various opcode functions such as `swap_monty`, `add_monty`, `sub_monty`, `div_monty`, and `mul_monty`.
- `opcodes_charlie.c`: Contains the implementation of various opcode functions such as `mod_monty`, `pchar_monty`, `pstr_monty`, `rotl_monty`, and `rotr_monty`.
- `theWay.c`: Contains the function `op_fun_res` which matches the opcode read from the bytecode file to the corresponding function and executes it.

### Functions

- `free_stack`: Frees a doubly linked list.
- `main`: Opens a Monty bytecode file, reads its instructions line by line, and executes them.
- `op_fun_res`: Matches the opcode read from the bytecode file to the corresponding function and executes it.
- Various opcode functions: Implement the functionality of the corresponding Monty opcodes.

## Installation, Compilation, Usage

To use the Monty bytecode interpreter, compile all the `.c` files in the repository and run the resulting executable with the path to a Monty bytecode file as an argument.

```bash
git clone https://github.com/ZeroDayPoke/holbertonschool-monty.git
cd holbertonschool-monty
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
./monty bytecode.m
```

## Environment

- Language: C
- OS: Ubuntu 14.04 LTS
- Compiler: gcc 4.8.4
- Style Guidelines: Betty style

## Authors

- **Lindsey Lancaster** - [linszay](https://github.com/linszay)
- **Chris Stamper** - [ZeroDayPoke](https://github.com/ZeroDayPoke)
