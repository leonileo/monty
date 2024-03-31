#include "monty.h"

/**
 * f_push - pushes an element to the stack
 *
 * @head: head of the linked list
 * @cline: line number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int cline)
{
	int n, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(head, n);
	else
		add_dnodeint_end(head, n);
}

/**
 * f_pall - prints all values on the stack
 *
 * @head: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}
