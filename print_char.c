#include "main.h"

/**
 * print_char - entry point
 *
 * Description: prints char
 * @arg: arg to be printed
 * Return: always returns void
 */

int print_char(va_list arg)
{
	int length = 1;
	char to_print;

	to_print = va_arg(arg, int);
	_putchar(to_print);

	return (length);
}
