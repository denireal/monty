#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
* struct bus_s - variables -args, file, line content
* @arg: value
* @file: pointer to monty file
* @content: line content
* @lifi: flag change stack <-> queue
* Description: carries values through the program
*/
typedef struct monty_s
{
char *arg;
FILE *file;
char *content;
int lifi;
}  monty_t;
extern monty_t monty_stat;

void s_swap(stack_t **stack_head, unsigned int line_counter);
void s_sub(stack_t **stack_head, unsigned int line_counter);
void s_stack(stack_t **stack_head, unsigned int line_counter);
void s_rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void s_rotl(stack_t **head, __attribute__((unused)) unsigned int line_counter);
void s_push(stack_t **stack_head, unsigned int line_counter);
void s_pstr(stack_t **stack_head, unsigned int line_counter);
void s_pop(stack_t **stack_head, unsigned int line_counter);
void s_pint(stack_t **stack_head, unsigned int line_counter);
void s_pchar(stack_t **stack_head, unsigned int line_counter);
void s_pall(stack_t **stack_head, unsigned int line_counter);
void s_nop(stack_t **stack_head, unsigned int line_counter);
void s_mul(stack_t **head, unsigned int line_counter);
void s_mod(stack_t **head, unsigned int line_counter);
void free_stack(stack_t *stack_head);
int exec_opcode(char *content, stack_t **stack, unsigned int line_counter,
FILE *file);
void s_div(stack_t **stack_head, unsigned int line_counter);
void s_add(stack_t **stack_head, unsigned int line_counter);
void s_queue(stack_t **stack_head, unsigned int line_counter);
void add_node_to_stack(stack_t **stack_head, int n);
void add_node_to_queue(stack_t **stack_head, int n);

#endif /* MONTY_H_ */
