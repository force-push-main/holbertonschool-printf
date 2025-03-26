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
	unsigned int abs_num;

	if (num < 0)
	{
		_putchar('-');
		abs_num = -num;
		return (convert_base_print(abs_num, base, 0) + 1);
	}

	return (convert_base_print(num, base, 0));
}
