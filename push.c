#include "monty.h"
#include <ctype.h>

/**
* s_push - This pushes an integer onto the stack or queue.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_push(stack_t **stack_head, unsigned int line_counter)
{
int value, index = 0;

/* Check if bus.arg is not NULL */
if (monty_stat.arg)
{
/* Handle the case where the argument starts with a '-' */
if (monty_stat.arg[0] == '-')
index++;

/* Check if the argument is a valid integer */
for (; monty_stat.arg[index] != '\0'; index++)
{
if (!isdigit(monty_stat.arg[index]))
{
fprintf(stderr, "L%d: usage: push integer\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}
}
}
else
{
/* If bus.arg is NULL, print an error and exit */
fprintf(stderr, "L%d: usage: push integer\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Convert the argument to an integer */
value = atoi(monty_stat.arg);

/* Add the integer to the stack or queue based on bus.lifi */
if (monty_stat.lifi == 0)
add_node_to_stack(stack_head, value);
else
add_node_to_queue(stack_head, value);
}
