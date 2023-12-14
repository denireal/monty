#include "monty.h"

/**
* s_queue - Sets the format of the data to a queue (FIFO).
* @stack_head: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
*/
void s_queue(stack_t **stack_head, unsigned int line_counter)
{
(void)stack_head;
(void)line_counter;
monty_stat.lifi = 1;
}

/**
* add_node_to_queue - Adds a node to the tail of the stack.
* @stack_head: A pointer to the head of the stack.
* @n: The value to be added to the new node.
*/
void add_node_to_queue(stack_t **stack_head, int n)
{
stack_t *queue_node, *current_node;

current_node = *stack_head;

/* Allocate memory for the new node */
queue_node = malloc(sizeof(stack_t));
if (queue_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/* Set the value and next pointer of the new node */
queue_node->n = n;
queue_node->next = NULL;

/* Traverse to the end of the stack to add the new node */
if (current_node)
{
while (current_node->next)
current_node = current_node->next;
}

/* If the stack is empty, set the new node as the head */
if (!current_node)
{
*stack_head = queue_node;
queue_node->prev = NULL;
}
else
{
/* Add the new node to the tail of the stack */
current_node->next = queue_node;
queue_node->prev = current_node;
}
}
