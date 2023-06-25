#include "monty.h"


void (*fetch_code(char *opc))(li_stck **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _activate_psh},
		{"pall", _activate_pal},
		{"pint", _activate_pnt},
		{"pop", _activate_pp},
		{"swap", _activate_swp},
		{"add", _activate_add},
		{"nop", _activate_np},
		{"sub", _activate_sb},
		{"div", _activate_dv},
		{"mul", _activate_ml},
		{"mod", _activate_md},
		{"pchar", _activate_pchar},
		{"pstr", _activate_ptsr},
		{"rotl", _activate_rtl},
		{"rotr", _activate_rtlrl},
		{"stack", _activate_stck},
		{"queue", _activate_que},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (_stamprc(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}

