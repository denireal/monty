#include "monty.h"

/**
* s_div - Divides the second top element of the stack by the top element.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_div(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;
int stack_length = 0, result;

current = *stack_head;

/* Count the number of elements in the stack */
for (; current; current = current->next)
stack_length++;

/* Check if the stack has at least two elements */
if (stack_length < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Check for division by zero */
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Compute the division and update the stack */
result = current->next->n / current->n;
current->next->n = result;
*stack_head = current->next;
free(current);
}
