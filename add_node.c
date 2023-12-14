#include "monty.h"

/**
* add_node_to_stack - Adds a new node to the top of the stack.
* @stack_head: A pointer to the head of the stack.
* @n: The value to be stored in the new node.
*/
void add_node_to_stack(stack_t **stack_head, int n)
{
stack_t *added_node, *result;

result = *stack_head;

/* Allocate memory for the new node */
added_node = malloc(sizeof(stack_t));
if (added_node == NULL)
{
fprintf(stderr, "Error: Unable to allocate memory\n");
exit(EXIT_FAILURE);
}

/* Update the previous pointer of the existing top node */
if (result)
result->prev = added_node;

/* Set the values for the new node */
added_node->n = n;
added_node->next = *stack_head;
added_node->prev = NULL;

/* Update the head pointer to point to the new node */
*stack_head = added_node;
}
