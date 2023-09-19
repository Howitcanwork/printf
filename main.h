#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int (*_pr_spf(char sp))(va_list, flags_t *);
int _write(char c);
int _write_str(char *s);
int pr_string(va_list a, flags_t *g);
int pr_char(va_list a, flags_t *g);
int pr_percent(va_list a, flags_t *g);
int _flag(char m, flags_t *g);
int pr_int(va_list a, flags_t *g);
void pr_num(int n);
int _length(int i);
int pr_binary(va_list a, flags_t *g);
int pr_unsigned(va_list a, flags_t *g);
int pr_octal(va_list a, flags_t *g);
int pr_hex(va_list a, flags_t *g);
int print_hex_big(va_list a, flags_t *g);
int pr_bigS(va_list a, flags_t *g);
int pr_address(va_list a, flags_t *g);
int pr_rev(va_list a, flags_t *g);
int pr_rot13(va_list a, flags_t *g);
char *convert(unsigned long int n, int b, int lc);

/**
 * struct flags - struct containing flags
 * @plus: '+' character
 * @space: ' ' character
 * @hash: '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printSpecifier - struct
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printSpecifier
{
	char c;
	int (*f)(va_list a, flags_t *f);
} ph;
