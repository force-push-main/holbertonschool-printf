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

	if (c < 0 || c > 127)
		return (0);

	_putchar(c);

	return (length);
}
