#include "monty.h"


li_stck *node_add_que(li_stck **head, const int n)
{
	li_stck *all_val, *alled_ace;

	if (head == NULL)
		return (NULL);
	all_val = malloc(sizeof(li_stck));
	if (!all_val)
	{
		dprintf(2, "Error: malloc failed\n");
		pro_vlog();
		exit(EXIT_FAILURE);
	}
	all_val->n = n;
	if (*head == NULL)
	{
		all_val->next = *head;
		all_val->prev = NULL;
		*head = all_val;
		return (*head);
	}
	alled_ace = *head;
	while (alled_ace->next)
		alled_ace = alled_ace->next;
	all_val->next = alled_ace->next;
	all_val->prev = alled_ace;
	alled_ace->next = all_val;
	return (alled_ace->next);
}


li_stck *node_add_lifo_que(li_stck **head, const int n)
{
	li_stck *all_val;

	if (head == NULL)
		return (NULL);
	all_val = malloc(sizeof(li_stck));
	if (!all_val)
	{
		dprintf(2, "Error: malloc failed\n");
		pro_vlog();
		exit(EXIT_FAILURE);
	}
	all_val->n = n;
	if (*head == NULL)
	{
		all_val->next = *head;
		all_val->prev = NULL;
		*head = all_val;
		return (*head);
	}
	(*head)->prev = all_val;
	all_val->next = (*head);
	all_val->prev = NULL;
	*head = all_val;
	return (*head);
}


void dixtinction_unique(li_stck *head)
{
	li_stck *vtns;

	while ((vtns = head) != NULL)
	{
		head = head->next;
		free(vtns);
	}
}

