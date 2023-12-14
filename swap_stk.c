#include "monty.h"

/**
* s_swap - Swaps the top two elements of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_swap(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current_node;
int stack_size, temp;

current_node = *stack_head;

/* Count the number of nodes in the stack */
for (stack_size = 0; current_node != NULL; stack_size++)
current_node = current_node->next;

/* Check if the stack has at least two elements */
if (stack_size < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

current_node = *stack_head;

/* Perform the swap */
temp = current_node->n;
current_node->n = current_node->next->n;
current_node->next->n = temp;
}
