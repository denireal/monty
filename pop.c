#include "monty.h"

/**
* s_pop - Removes the top element of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_pop(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;

/* Check if the stack is empty */
if (*stack_head == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Remove the top element of the stack */
current = *stack_head;
*stack_head = current->next;
free(current);
}
