#include "monty.h"


void _activate_rtl(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax_f = NULL;
	li_stck *val_ax_t = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->nw_nt == NULL)
		return;

	val_ax_f = (*doubly)->nw_nt;
	val_ax_t = *doubly;

	for (; val_ax_t->nw_nt != NULL; val_ax_t = val_ax_t->nw_nt)
		;

	val_ax_f->init_al = NULL;
	val_ax_t->nw_nt = *doubly;
	(*doubly)->nw_nt = NULL;
	(*doubly)->init_al = val_ax_t;
	*doubly = val_ax_f;
}


void _activate_rtlrl(li_stck **doubly, unsigned int cline)
{
	li_stck *val_ax = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->nw_nt == NULL)
		return;

	val_ax = *doubly;

	for (; val_ax->nw_nt != NULL; val_ax = val_ax->nw_nt)
		;

	val_ax->init_al->nw_nt = NULL;
	val_ax->nw_nt = *doubly;
	val_ax->init_al = NULL;
	(*doubly)->init_al = val_ax;
	*doubly = val_ax;
}

