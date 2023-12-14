#include "monty.h"

/**
* s_sub - Subtracts the top element of the stack from the second
* top element.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_sub(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current_node;
int result, stack_size;

current_node = *stack_head;

/* Count the number of nodes in the stack */
for (stack_size = 0; current_node != NULL; stack_size++)
current_node = current_node->next;

/* Check if the stack has at least two elements */
if (stack_size < 2)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Perform the subtraction */
current_node = *stack_head;
result = current_node->next->n - current_node->n;
current_node->next->n = result;
*stack_head = current_node->next;
free(current_node);
}
