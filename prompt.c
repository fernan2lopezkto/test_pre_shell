#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>





/**
 * main - try prompt
 *
 * @ac: arguments counter
 * @tv: arguments array
 *
 * Return: int
 */
int main(void)
{
	size_t bufsize = 512;
	char *buffer;
	char *token;
	char **args = malloc(bufsize * sizeof(char*));
	int positions, i;

	do
	{
		if (!args)
			exit (0);

   
		i = 0;
		positions = 0;
   
		   buffer = (char *)malloc(bufsize * sizeof(char));
		   if( buffer == NULL)
		   	exit(1);

		/*  get a line from user  */
		printf("$ ");
		getline(&buffer, &bufsize, stdin);
		
		/*split these line and put in pointers array*/
		token = strtok(buffer, " ");
		while( token != NULL )
		{	/*	args[positions] = malloc(sizeof(char) * sizeof(token) + 1); */
			args[positions] = token;
			if (args[positions] != NULL)
			{
				printf("in token position %d: %s\t\t\t", positions, token);
				printf("in args position %d: %s\n", positions, args[positions]);
			}
			token = strtok(NULL, " ");	
			positions++;
		}

		args[positions] = NULL;

		free(buffer);

		
		while (args[i] != NULL)
		{
			printf("in while loop position %d: %s\n", i, args[i]);
			i++;
		}
		
		free(args);
		
	} while (1);
    
	return(0);
}
