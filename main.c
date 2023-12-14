#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/* Global variable to store information about the program */
monty_t monty_stat = {NULL, NULL, NULL, 0};

/**
* main - Interpreter for Monty code
* @argc: Number of command-line arguments
* @argv: Location of the Monty file
* Return: 0 upon successful execution
*/
int main(int argc, char *argv[])
{
char *content;
FILE *file;
size_t size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int line_counter = 0;

/* Check if the correct number of arguments is provided */
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

/* Open the Monty file for reading */
file = fopen(argv[1], "r");
monty_stat.file = file;

/* Check if the file can be opened successfully */
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

/* Read and execute Monty code line by line */
while (read_line > 0)
{
content = NULL;
read_line = getline(&content, &size, file);
monty_stat.content = content;
line_counter++;

/* Execute opcode if the line is not empty */
if (read_line > 0)
{
exec_opcode(content, &stack, line_counter, file);
}

/* Free allocated memory for the line content */
free(content);
}

/* Free the stack and close the file */
free_stack(stack);
fclose(file);

return (0);
}
