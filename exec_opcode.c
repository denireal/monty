#include "monty.h"

/**
* exec_opcode - Executes the specified opcode.
* @content: The content of the instruction.
* @stack: A pointer to the head of the stack.
* @line_counter: The current line number being processed.
* @file: The file being read.
* Return: 0 on success, 1 on failure.
*/
int exec_opcode(char *content, stack_t **stack, unsigned int line_counter,
FILE *file)
{
instruction_t opcodes[] = {
{"push", s_push}, {"pall", s_pall}, {"pint", s_pint},
{"pop", s_pop},
{"swap", s_swap},
{"add", s_add},
{"nop", s_nop},
{"sub", s_sub},
{"div", s_div},
{"mul", s_mul},
{"mod", s_mod},
{"pchar", s_pchar},
{"pstr", s_pstr},
{"rotl", s_rotl},
{"rotr", s_rotr},
{"queue", s_queue},
{"stack", s_stack},
{NULL, NULL}
};

unsigned int i = 0;
char *opcode;

opcode = strtok(content, " \n\t");
if (opcode && opcode[0] == '#')
return (0);

monty_stat.arg = strtok(NULL, " \n\t");

while (opcodes[i].opcode && opcode)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
{
opcodes[i].f(stack, line_counter);
return (0);
}
i++;
}

if (opcode && opcodes[i].opcode == NULL)
{
fprintf(stderr, "L%d: Instruction not recognized %s\n", line_counter, opcode);
fclose(file);
free(content);
free_stack(*stack);
exit(EXIT_FAILURE);
}

return (1);
}
