#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
 *
 *
 *
 */
char *prompt(void)
{
	size_t bufsize = 512;
	char *buffer;

	buffer = malloc(bufsize * sizeof(char));
	if( buffer == NULL)
		exit (1);

	printf("$ ");
	getline(&buffer, &bufsize, stdin);

	return (buffer);
}

/**
 * 
 */
char **tok(char *line)
{
	char *token;
	char **args = malloc(sizeof(char *) * 20);
	int positions = 0;

	printf("\n%s\n", line);


	token = strtok(line, " ");
	if(token != NULL)
	{
		while(token != NULL)
		{
			args[positions] = strdup(token);
			positions++;
			token = strtok(NULL, " ");
		}
	}
	args[positions] = NULL;
	return (args);
}

/**
 *
 */
int exec(char **args)
{
	int i = 0;
	pid_t pid;
	int status;

	while (args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		if (i > 1)
		{
			printf("\nstarting procsess\t\t\t\t");
			printf("pid: %u\n", getpid());
			sleep(1);
			execve(args[0], args, NULL);
			sleep(1);
			printf("\nend procsess\n");
			sleep(1);
		}
		else
		{
			printf("\ninvalid input.. .\n");
		}
	}
	else
	{
		wait(&status);
		printf("\n\nreturned the previous process successful\n");
		printf("naw the pid be again: %u\n\n", getpid());
	}
	return(0);
}
