#ifndef HOLY_GRAIL_H_
#define HOLY_GRAIL_H_

/* our one allowed global */
extern char **theGrail;

/*
 * libraries - to be included
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>

/*
 * structs below
 */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*
 * prototypes - function protos below
 */
int write_to_SO(char c);
int write_to_SE(char c);
void errHand(int eNum, char *errArg, unsigned int lNum);
void write_error(char *str);
void op_fun_res(unsigned int lineCount);
void push_monty_stack(stack_t **stack, unsigned int line_number);
void pall_monty_stack(stack_t **stack, unsigned int line_number);
void pint_monty_stack(stack_t **stack, unsigned int line_number);
void pop_monty_stack(stack_t **stack, unsigned int line_number);
void swap_monty_stack(stack_t **stack, unsigned int line_number);
void nop_monty_stack(stack_t **stack, unsigned int line_number);

#endif
