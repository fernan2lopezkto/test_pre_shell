#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *path = getenv("PATH");
	char *token;
	char *directory;
	char *p;
	struct stat coso;
	int i = 1;

	if (av[1] == NULL)
	{
		printf("enter file in arguments 1.. .\n");
		return (1);
	}

	while (i < ac)
	{
		p = strdup(path);
		printf("\n\nserch %s in PATH.. .\n", av[i]);
		token = strtok(p, ":");
		if(token != NULL)
		{
			while (token != NULL)
			{
				directory = strdup(token);
				strcat(directory, "/");
				strcat(directory, av[i]);
				if (stat(directory, &coso) == 0)
				{
					printf("file found in: %s\n", token);
				}
				token = strtok(NULL, ":");
			}
		}
		i++;
	}
	return (0);
}
