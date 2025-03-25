#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct Print_Function - Struct containing specifier and function
 *
 * @specifier: char passed to specify type of arg
 * @print_va: relevant function to print arg
 */

typedef struct Print_Function
{
	char spec;
	int (*print_func)(va_list arg);
} Spec_N_Func;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);

#endif
