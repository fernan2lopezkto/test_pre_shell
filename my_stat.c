#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	struct stat coso;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	if (stat(av[1], &coso) == 0)
	{
		printf("--FOUND--\n");
		sleep(1);
		if (execve(av[1], av, NULL) == -1)
			perror("Error:");
	}
	return (0);
}
