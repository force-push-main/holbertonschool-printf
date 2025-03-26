#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

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


int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list arg);
int convert_base_print(unsigned int num, int base, int len);
int convert_base_print_lowercase(unsigned int num, int base, int len);
int convert_address_print(uintptr_t num, int len);
int print_int(va_list arg);
int print_unsign_int(va_list arg);
int print_unsign_bin(va_list arg);
int print_unsign_oct(va_list arg);
int print_unsign_hex(va_list arg);
int print_unsign_hex_lowercase(va_list arg);
int print_ptr_address(va_list arg);

#endif
