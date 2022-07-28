#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	int status, i = 0;

	printf("\nStarting program\t\t\t\t");
	printf("pid: %u\n", getpid());
	sleep(3);

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("\nstarting procsess\t\t\t\t");
			printf("pid: %u\n", getpid());
			sleep(3);
			execve(argv[0], argv, NULL);
			sleep(3);
		}
		else
		{
			wait(&status);
			printf("\n\nreturned the previous process successful\n");
			printf("naw the pid be again: %u\n\n", getpid());
		}
		i++;
	}
	return (0);
}
