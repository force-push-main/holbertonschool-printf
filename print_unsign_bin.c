#include "main.h"

/**
 * print_unsign_bin - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted to base two and printed
 * Return: returns length of string
 */

int print_unsign_bin(va_list arg)
{
	int base = 2;
	unsigned int num = va_arg(arg, unsigned int);

	return (convert_base_print(num, base, 0));
}
