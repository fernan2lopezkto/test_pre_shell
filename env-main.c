#include <stdio.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *name);
/**
 *
 */
int main(int ac, char **av)
{
	char *var_val = _getenv(av[1]);

	if (ac == 2)
	{
		if (!var_val)
		{
			printf("env var not found.. .\n");
		}
		else
		{
			printf("%s\n", var_val);
		}
	}
	else
	{
		printf("incorrect input.. .\n");
	}
	return (0);
}
/**
 
 
 
 *
 */
char *_getenv(const char *name)
{
	int i = 0, j;
	int status = 1;

	while (environ[i])
	{
		status = 1;
		j = 0;
		while (environ[i][j] != '=')
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		j++;
		}
		if (status)
		{
			return(&environ[i][j + 1]);
		}
	i++;
	}
	printf("\n------------------\n");

	return (NULL);
}
