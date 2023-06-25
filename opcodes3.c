#include "monty.h"


void _activate_rtl(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax_f = NULL;
	li_stck *val_ax_t = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	val_ax_f = (*doubly)->next;
	val_ax_t = *doubly;

	for (; val_ax_t->next != NULL; val_ax_t = val_ax_t->next)
		;

	val_ax_f->prev = NULL;
	val_ax_t->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = val_ax_t;
	*doubly = val_ax_f;
}


void _activate_rtlrl(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	val_ax = *doubly;

	for (; val_ax->next != NULL; val_ax = val_ax->next)
		;

	val_ax->prev->next = NULL;
	val_ax->next = *doubly;
	val_ax->prev = NULL;
	(*doubly)->prev = val_ax;
	*doubly = val_ax;
}

