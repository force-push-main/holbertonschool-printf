#include "main.h"

/**
 * convert_base_print - Entry point
 *
 * Description: prints num in requested base and returns printed length
 * @num: num to be converted
 * @base: base to be converted to
 * @len: running count of chars printed
 * Return: returns num of characters printed
 */

int convert_base_print_lowercase(unsigned int num, int base, int len)
{
	char *characters = "0123456789abcdef";

	if (num / base != 0)
	{
		len = convert_base_print_lowercase(num / base, base, len);
		_putchar(characters[num % base]);
		return (len + 1);
	}
	_putchar(characters[num % base]);
	return (len + 1);
}
