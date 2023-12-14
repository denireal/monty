#include "monty.h"

/**
* s_mul - Multiplies the second top element of the stack
* by the top element.
* @head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
* Return: No return value.
*/
void s_mul(stack_t **head, unsigned int line_counter)
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
fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*head);
exit(EXIT_FAILURE);
}

/* Compute the multiplication and update the stack */
current = *head;
result = current->next->n * current->n;
current->next->n = result;
*head = current->next;
free(current);
}
