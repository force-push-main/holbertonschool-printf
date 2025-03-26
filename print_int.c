#include "main.h"

/**
 * print_int - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted to base ten and printed
 * Return: returns length of string
 */

int print_int(va_list arg)
{
	int base = 10;
	int num = va_arg(arg, int);

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}

	return (convert_base_print(num, base, 0));
}
