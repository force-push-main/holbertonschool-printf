#include "main.h"

/**
 * print_hex - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted to base sixteen and printed
 * Return: returns length of string
 */

int print_unsign_hex_lowercase(va_list arg)
{
	int base = 16;
	int num = va_arg(arg, int);

	return (convert_base_print_lowercase(num, base, 0));
}
