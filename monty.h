#ifndef _MONTY_H_ 
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define ERROR_MALLOC 0
#define ERROR_USAGE_FILE 1
#define ERROR_OPEN_FILE 2
#define ERROR_UNKNOWN 3
#define ERROR_PUSH 4
#define ERROR_PINT 5
#define ERROR_POP 6
#define ERROR_SWAP 7
#define ERROR_ADD 8
#define ERROR_MOD 13
#define ERROR_STACK_EMPTY 14

#define TRUE (1 == 1)
#define FALSE (!TRUE)
#define BUFSIZE 1024
#define LIFO 1
#define FIFO 0

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inventory_s - a struct pointing to all other structs for this project
 * @filename: the filename from argv[1]
 * @stack: pointer to stack
 * @line: input line received from getline
 * @input: lines of the files parsed into separate elements
 * @linenum: the linenumber
 * @file: the input file
 * @order: LIFO or FIFO, stack or queue
 */
typedef struct inventory_s
{
	char *filename;
	stack_t *stack;
	char *line;
	char **input;
	unsigned int linenum;
	FILE *file;
	int order;
} inventory_t;

extern inventory_t *inventory;
inventory_t *inventory;

int build_inventory(void);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

void free_all(void);
void free_stack(void);
void handle_errors(int e);

#endif