#include "monty.h"

/**
* s_add - Adds the top two elements of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_add(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;
int stack_length = 0, result;

current = *stack_head;

while (current)
{
current = current->next;
stack_length++;
}


if (stack_length < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

result = current->n + current->next->n;
current->next->n = result;
*stack_head = current->next;
free(current);
}
