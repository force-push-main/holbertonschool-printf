#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct Print_Function - Struct containing specifier and function
 *
 * @spec: char passed to specify type of arg
 * @print_func: relevant function to print arg
 */

typedef struct Print_Function
{
	char spec;
	int (*print_func)(va_list arg);
} Spec_N_Func;


/**
 * Add all function prototypes below this line
 * ===========================================
 */

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int convert_base_print(int num, int base, int len);
int print_bin(va_list arg);
int print_oct(va_list arg);
int print_hex(va_list arg);

#endif
