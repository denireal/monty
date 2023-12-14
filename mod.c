#include "monty.h"

/**
* s_mod - Computes the modulo of the second top element of the stack
* by the top element.
* @head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_mod(stack_t **head, unsigned int line_counter)
{
stack_t *current;
int stack_length = 0, result;

current = *head;

/* Count the number of elements in the stack */
while (current)
{
current = current->next;
stack_length++;
}

/* Check if the stack has at least two elements */
if (stack_length < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Check for division by zero */
if (current->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Compute the modulo and update the stack */
result = current->next->n % current->n;
current->next->n = result;
*head = current->next;
free(current);
}
