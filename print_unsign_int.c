#include "main.h"

/**
 * print_unsign_int - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted to base ten and printed
 * Return: returns length of string
 */

int print_unsign_int(va_list arg)
{
	int base = 10;
	unsigned int num = va_arg(arg, unsigned int);

	return (convert_base_print(num, base, 0));
}
