#include "monty.h"

int _stamprc(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}


int _all_chs(char *s, char c)
{
	int tont = 0;

	while (s[tont] != '\0')
	{
		if (s[tont] == c)
		{
			break;
		}
		tont++;
	}
	if (s[tont] == c)
		return (1);
	else
		return (0);
}


char *_all_strks(char *s, char *d)
{
	static char *all_u_l_u;
	int i = 0, j = 0;

	if (!s)
		s = all_u_l_u;
	while (s[i] != '\0')
	{
		if (_all_chs(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			all_u_l_u = s + i + 1;
			*all_u_l_u = '\0';
			s = s + j;
			return (s);
		}
		else if (_all_chs(d, s[i]) == 0 && _all_chs(d, s[i + 1]) == 0)
			i++;
		else if (_all_chs(d, s[i]) == 0 && _all_chs(d, s[i + 1]) == 1)
		{
			all_u_l_u = s + i + 1;
			*all_u_l_u = '\0';
			all_u_l_u++;
			s = s + j;
			return (s);
		}
		else if (_all_chs(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

