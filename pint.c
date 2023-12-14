#include "monty.h"

/**
* s_pint - Prints the value at the top of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_pint(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current = *stack_head;

/* Check if the stack is empty */
if (current == NULL)
{
fprintf(stderr, "L%u: can't pint, stack is empty\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Print the value at the top of the stack */
printf("%d\n", current->n);
}
