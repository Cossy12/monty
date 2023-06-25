#include "monty.h"

void _activate_psh(li_stck **doubly, unsigned int cline)
{
	int n, j;

	if (!vlgoed.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vlgoed.arg[j] != '\0'; j++)
	{
		if (!isdigit(vlgoed.arg[j]) && vlgoed.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			pro_vlog();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vlgoed.arg);

	if (vlgoed.l_i_f_o == 1)
		node_add_lifo_que(doubly, n);
	else
		node_add_que(doubly, n);
}


void _activate_pal(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax;
	(void)cline;

	val_ax = *doubly;

	while (val_ax)
	{
		printf("%d\n", val_ax->n);
		val_ax = val_ax->next;
	}
}



void _activate_pnt(li_stck **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}


void _activate_pp(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}
	val_ax = *doubly;
	*doubly = (*doubly)->next;
	free(val_ax);
}



void _activate_swp(li_stck **doubly, unsigned int cline)
{
	int m = 0;
	li_stck *val_ax = NULL;

	val_ax = *doubly;

	for (; val_ax != NULL; val_ax = val_ax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	val_ax = *doubly;
	*doubly = (*doubly)->next;
	val_ax->next = (*doubly)->next;
	val_ax->prev = *doubly;
	(*doubly)->next = val_ax;
	(*doubly)->prev = NULL;
}

