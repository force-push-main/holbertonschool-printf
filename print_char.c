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

	char c;

	c = va_arg(arg, int);

	_putchar(c);

	return (length);
}
