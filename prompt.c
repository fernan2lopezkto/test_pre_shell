#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef struct toklist
{
	char *str;
	struct toklist *next;
} toklist;


toklist *add_node_end(toklist **head, const char *str);
size_t print_list(const toklist *h);
int free_list(toklist *head);


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
	char *buffer;
	char *token;
	size_t bufsize = 32;
	toklist *words;
    int i = 1;

    while (i)
    {
   
    	words = NULL;

	    buffer = (char *)malloc(bufsize * sizeof(char));
	    if( buffer == NULL)
	    	exit(1);

	    printf("$ ");
	    getline(&buffer, &bufsize, stdin);

	    token = strtok(buffer, " ");
	    while( token != NULL )
	    	{
		    	add_node_end(&words, token);
		    	token = strtok(NULL, " ");
		    }

    	free(buffer);

	    print_list(words);

	    free_list(words);
    }
	return(0);
}


/**
 *add_node_end - add new node to the end of the list
 *@head: new node
 *@str: item to node
 *Return: new node
 */
toklist *add_node_end(toklist **head, const char *str)
{
	toklist *new;
	toklist *last = *head;

	new = malloc(sizeof(toklist));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;

		last->next = new;
	}
	return (new);
}


/**
 *print_list - print list items
 *@h: nodo
 *Return: counter
 */
size_t print_list(const toklist *h)
{
	size_t counter = 0;
	const toklist *tmp = h;

	while (tmp)
	{
		if (tmp->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
			printf("%s\n", tmp->str);
		}
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}


/**
 *free_list - free the list
 *@head: list start
 *Return: alwais 0
 */
int free_list(toklist *head)
{
	toklist *tmp;

	if (head != NULL)
	{
		while (head)
		{
			tmp = head->next;
			free(head->str);
			free(head);
			head = tmp;
		}
	}
	return (0);
}