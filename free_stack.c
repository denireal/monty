#include "monty.h"

/**
* free_stack - Frees all nodes in a stack.
* @stack_head: A pointer to the head of the stack.
*/
void free_stack(stack_t *stack_head)
{
stack_t *current_node;

/* Traverse the stack and free each node */
for (current_node = stack_head; stack_head; current_node = stack_head)
{
stack_head = stack_head->next;
free(current_node);
}
}
