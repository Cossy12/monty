#include "monty.h"


void _activate_add(li_stck **doubly, unsigned int cline)
{
	int m = 0;
	li_stck *val_ax = NULL;

	val_ax = *doubly;

	for (; val_ax != NULL; val_ax = val_ax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	val_ax = (*doubly)->next;
	val_ax->n += (*doubly)->n;
	_activate_pp(doubly, cline);
}


void _activate_np(li_stck **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}


void _activate_sb(li_stck **head, unsigned int cline)
{
	int m = 0;
	li_stck *nw_val;

	nw_val = *head;

	for (; nw_val != NULL; nw_val = nw_val->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	nw_val = (*head)->next;
	nw_val->n -= (*head)->n;
	_activate_pp(head, cline);
}



void _activate_dv(li_stck **doubly, unsigned int cline)
{
	int m = 0;
	li_stck *val_ax = NULL;

	val_ax = *doubly;

	for (; val_ax != NULL; val_ax = val_ax->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	val_ax = (*doubly)->next;
	val_ax->n /= (*doubly)->n;
	_activate_pp(doubly, cline);
}



void _activate_ml(li_stck **head, unsigned int cline)
{
	int m = 0;
	li_stck *nw_val;

	nw_val = *head;

	for (; nw_val != NULL; nw_val = nw_val->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		pro_vlog();
		exit(EXIT_FAILURE);
	}

	nw_val = (*head)->next;
	nw_val->n *= (*head)->n;
	_activate_pp(head, cline);
}

