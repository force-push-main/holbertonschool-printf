#include "main.h"

/**
 * print_bin - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted and printed
 * Return: returns length of string
 */

int print_bin(va_list arg)
{
	int base = 2;
	int num = va_arg(arg, int);

	return (convert_base_print(num, base, 0));
}
