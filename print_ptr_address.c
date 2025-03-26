#include "main.h"

/**
 * print_ptr_address - Entry point
 *
 * Description: calls recursive convert and print function
 * @arg: int to be converted to base sixteen and printed
 * Return: returns length of string
 */

int print_ptr_address(va_list arg)
{
	uintptr_t num = va_arg(arg, uintptr_t);

	_putchar('0');
	_putchar('x');

	return (convert_address_print(num, 0) + 2);
}
