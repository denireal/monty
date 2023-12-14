#include "monty.h"

/**
* s_rotl - Rotates the stack to the top.
* @head: A pointer to the head of the stack.
* @line_counter: The current line number being processed (unused).
*/
void s_rotl(stack_t **head, __attribute__((unused)) unsigned int line_counter)
{
stack_t *last_node = *head, *second_node;

/* Check if the stack is empty or has only one element */
if (*head == NULL || (*head)->next == NULL)
{
return;
}

second_node = (*head)->next;
second_node->prev = NULL;

/* Traverse to the end of the stack */
while (last_node->next != NULL)
{
last_node = last_node->next;
}

/* Perform the left rotation */
last_node->next = *head;
(*head)->next = NULL;
(*head)->prev = last_node;
(*head) = second_node;
}
