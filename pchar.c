#include "monty.h"

/**
* s_pchar - Prints the character at the top of the stack.
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_pchar(stack_t **stack_head, unsigned int line_counter)
{
stack_t *current;

current = *stack_head;

/* Check if the stack is empty */
if (!current)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Check if the value is out of range */
if (current->n > 127 || current->n < 0)
{
fprintf(stderr, "L%d: can't pchar, out of range\n", line_counter);
fclose(monty_stat.file);
free(monty_stat.content);
free_stack(*stack_head);
exit(EXIT_FAILURE);
}

/* Print the character at the top of the stack */
printf("%c\n", current->n);
}
