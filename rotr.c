#include "monty.h"

/**
* s_rotr - Rotates the stack to the bottom.
* @head: A pointer to the head of the stack.
* @line_counter: The current line number being processed (unused).
*/
void s_rotr(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
stack_t *last_node;

/* Check if the stack is empty or has only one element */
if (*head == NULL || (*head)->next == NULL)
{
return;
}

last_node = *head;

/* Traverse to the end of the stack */
while (last_node->next)
{
last_node = last_node->next;
}

/* Perform the right rotation */
last_node->next = *head;
last_node->prev->next = NULL;
last_node->prev = NULL;
(*head)->prev = last_node;
(*head) = last_node;
}
