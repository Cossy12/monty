#include "monty.h"
void (*f)(li_stck **stack, unsigned int line_number);
all_gb vlgoed;

void pro_vlog(void)
{
	dixtinction_unique(vlgoed.strt_hd);
	free(vlgoed.wa_it);
	fclose(vlgoed.fd);
}


void ign_vlog(FILE *fd)
{
	vlgoed.l_i_f_o = 1;
	vlgoed.tomt = 1;
	vlgoed.arg = NULL;
	vlgoed.strt_hd = NULL;
	vlgoed.fd = fd;
	vlgoed.wa_it = NULL;
}


FILE *auth_inpt(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}


int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	ssize_t x_obj = 0;
	char *st_lns[2] = {NULL, NULL};

	fd = auth_inpt(argc, argv);
	ign_vlog(fd);
	x_obj = getline(&vlgoed.wa_it, &size, fd);
	while (x_obj != -1)
	{
		st_lns[0] = _all_strks(vlgoed.wa_it, " \t\n");
		if (st_lns[0] && st_lns[0][0] != '#')
		{
			f = fetch_code(st_lns[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vlgoed.tomt);
				dprintf(2, "unknown instruction %s\n", st_lns[0]);
				pro_vlog();
				exit(EXIT_FAILURE);
			}
			vlgoed.arg = _all_strks(NULL, " \t\n");
			f(&vlgoed.strt_hd, vlgoed.tomt);
		}
		x_obj = getline(&vlgoed.wa_it, &size, fd);
		vlgoed.tomt++;
	}

	pro_vlog();

	return (0);
}

