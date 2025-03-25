#include "main.h"
#include <unistd.h>

/**
 * _printf - Entry point
 *
 * Description: prints to std output based on format
 * @format: array of chars indicating format for args
 * Return: number of chars printed excluding null terminator
 */

int _printf(const char *format, ...)
{
	Spec_N_Func spec_n_func[] = {
		{'c', print_char},
	};

	int i, j;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < 1 && format[i] != spec_n_func[j].spec; j++)
			{
				if (format[i + 1] == spec_n_func[j].spec)
				{
					spec_n_func[j].print_func(args);
					i = i + 2;
				}
			}
		}
		_putchar(format[i]);
	}

	return (1);
}
