#include "main.h"

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
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_unsign_bin},
		{'u', print_unsign_int},
		{'o', print_unsign_oct},
		{'x', print_unsign_hex_lowercase},
		{'X', print_unsign_hex},
		{'p', print_ptr_address}
	};

	int i, j, string_len, length, found;

	va_list args;

	va_start(args, format);

	length = 0;

	for (i = 0; format[i]; i++)
		string_len++;

	for (i = 0; i < string_len; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			length++;
		}
		if (format[i] == '%')
		{
			found = 0;
			for (j = 0; j < 10 && !found; j++)
			{
				if (format[i + 1] == spec_n_func[j].spec)
				{
					length += spec_n_func[j].print_func(args);
					i++;
					found = 1;
				}
				if (format[i + 1] == '%' && !found)
				{
					_putchar('%');
					i++;
					length++;
					found = 1;
				}
			}
			if (!found)
			{
				_putchar(format[i]);
				i++;
				length++;
			}
		}
	}
	return (length);
}
