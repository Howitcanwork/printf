o#include "main.h"

/**
 * _flag - turns on flag
 * @sp: character
 * @g: pointer
 * Return: 1
 */

int _flag(char sp, flags_t *g)
{
	int j = 0;

	switch (sp)
	{
		case '+':
			g->plus = 1;
			j = 1;
			break;

		case ' ':
			g->space = 1;
			j = 1;
			break;

		case '#':
			g->hash = 1;
			j = 1;
			break;
	}
	return (j);
}
