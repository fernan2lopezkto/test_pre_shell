#include <stdio.h>
#include "main.h"
#include <stdlib.h>
/**
 * main - whit out arguments
 * onli call system
 * Return: 0
 */
int main(void)
{
	char *line;
	char **args;

	do
	{
	line = prompt();

	args = tok(line);

	exec(args);

	free(args);
	free(line);

	} while (1);
}
