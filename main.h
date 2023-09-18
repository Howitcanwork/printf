#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
void _print_simple(int std, const char *string, int leng);
void _pr_str(int std, const char *string, int *chara_print);
void _pr_perc(int std, int *chara_print);
void _pr_num(int std, int i, int *chara_print);
void _specifiers(int std, char specf, va_list argu, int *chara_print);
int _printf(const char *format, ...);

#endif
