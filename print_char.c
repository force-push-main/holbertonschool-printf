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
/**
 * Explanation:
 *
 * c = va_arg(arg, int) - initialises c to equal the value of arg, then...
 * moves to the next value in the arg array (not actually an array but easier to think of it like that)
 * Importantly, by moving to the next value in the arg array here, all instances of arg in all 
 * functions are now also equal to that value
 * e.g. if arg = [1, 2, 3], running the va_arg command here will return 1 and ...
 * move arg to the next value, 2.
 * If you run the va_arg command again, either here or in the _printf function (or wherever you want), it will return 2, and so on
 */

	if (c < 0 || c > 127)
		return (0);

	_putchar(c);

	return (length);
}
