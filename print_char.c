#include "main.h"

void print_char(va_list arg)
{
	char to_print;
	to_print = va_arg(arg, int);
	_putchar(to_print);
}
