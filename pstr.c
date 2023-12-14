#include "monty.h"

/**
* s_pstr - Prints the string starting from the top of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_pstr(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;

(void)line_counter;  /* Unused parameter */

current = *stack_head;

while (current)
{
/* Break if the value is not a printable ASCII character */
if (current->n > 127 || current->n <= 0)
{
break;
}

/* Print the character */
printf("%c", current->n);

current = current->next;
}

/* Print a newline at the end */
printf("\n");
}
