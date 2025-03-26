#include "main.h"

/**
 * convert_address_print - Entry point
 *
 * Description: prints num in requested base and returns printed length
 * @num: num to be converted
 * @len: running count of chars printed
 * Return: returns num of characters printed
 */

int convert_address_print(uintptr_t num, int len)
{
	char *characters = "0123456789abcdef";

	if (num / 16 != 0)
	{
		len = convert_address_print(num / 16, len);
		_putchar(characters[num % 16]);
		return (len + 1);
	}
	_putchar(characters[num % 16]);
	return (len + 1);
}
