#include "monty.h"

/**
* s_pall - Prints all the elements of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number (not used in this function).
* Return: No return value.
*/
void s_pall(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;

(void)line_counter;  /* Unused parameter */

current = *stack_head;

if (current == NULL)
return;

/* Traverse the stack and print each element */
while (current)
{
printf("%d\n", current->n);
current = current->next;
}
}
