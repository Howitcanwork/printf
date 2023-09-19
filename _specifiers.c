#include "main.h"

/**
 * _pr_spf - printing functions
 * @sp: conversion specifier
 * Return: pointer
 */

int (*_pr_spf(char sp))(va_list, flags_t *)
{

	ph specifier_array[] = {
		{'c', pr_char},
		{'s', pr_string},
		{'%', pr_percent},
		{'d', pr_int},
		{'i', pr_int},
		{'u', pr_unsigned},
		{'x', pr_hex},
		{'X', pr_hex_big},
		{'b', pr_binary},
		{'o', pr_octal},
		{'R', pr_rot13},
		{'r', pr_rev},
		{'S', pr_bigS},
		{'p', pr_address}
		};

	int flags = 14;

	register int x;

	for (x = 0; x < flags; x++)
		if (specifier_array[x].c == sp)
			return (specifier_array[x].f);
	return (NULL);
}
