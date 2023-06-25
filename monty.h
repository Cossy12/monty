#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct val_stack
{
	int n;
	struct val_stack *init_al;
	struct val_stack *nw_nt;
} li_stck;


typedef struct all_globals
{
	int l_i_f_o;
	unsigned int tomt;
	char  *arg;
	li_stck *strt_hd;
	FILE *fd;
	char *wa_it;
} all_gb;




typedef struct follow_f
{
	char *vai_op_cd;
	void (*f)(li_stck **stack, unsigned int line_number);
} follow_aft;

extern all_gb vlgoed;

/* opcode_instructuions*/
void _activate_psh(li_stck **stack, unsigned int line_number);
void _activate_pal(li_stck **stack, unsigned int line_number);
void _activate_pnt(li_stck **doubly, unsigned int cline);
void _activate_pp(li_stck **doubly, unsigned int cline);
void _activate_swp(li_stck **doubly, unsigned int cline);
void _activate_que(li_stck **doubly, unsigned int cline);
void _activate_stck(li_stck **doubly, unsigned int cline);
void _activate_add(li_stck **doubly, unsigned int cline);
void _activate_np(li_stck **doubly, unsigned int cline);
void _activate_sb(li_stck **doubly, unsigned int cline);
void _activate_dv(li_stck **doubly, unsigned int cline);
void _activate_ml(li_stck **doubly, unsigned int cline);
void _activate_md(li_stck **doubly, unsigned int cline);
void _activate_pchar(li_stck **doubly, unsigned int cline);
void _activate_ptsr(li_stck **doubly, unsigned int cline);
void _activate_rtl(li_stck **doubly, unsigned int cline);
void _activate_rtlrl(li_stck **doubly, unsigned int cline);

void (*fetch_code(char *opc))(li_stck **stack, unsigned int line_number);

int _all_chs(char *s, char c);
char *_all_strks(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _stamprc(char *s1, char *s2);

li_stck *node_add_que(li_stck **head, const int n);
li_stck *node_add_lifo_que(li_stck **head, const int n);
void dixtinction_unique(li_stck *head);

void pro_vlog(void);

#endif 

