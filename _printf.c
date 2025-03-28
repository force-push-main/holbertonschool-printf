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
/*FUNCTION 1*/
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
	}; /*could move this to a seperate function*/
/*FUNCTION 1*/
	
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
		if (format[i] == '%') /*we can move this to a seperate function too, for when % is found run function*/
		{ 
/*FUNCTION 2 - length = found_percentage(length) - to update the length from this function running*/
			
			found = 0; /*found used to break the for loop for when spec is from our list*/
			for (j = 0; j < 10 && !found; j++) 
			{
				if (format[i + 1] == spec_n_func[j].spec) /*note:if the next char after % is = to spec*/
				{
					length += spec_n_func[j].print_func(args);
					i++;
					found = 1; /*i++ & found = 1 for both these ifs can be moved outside as one*/
				}
				if (format[i + 1] == '%' && !found)
				{
					_putchar('%');
					i++;
					length++;
					found = 1; /*i++ & found = 1 for both these ifs can be moved outside as one*/
				}
			}
			if (!found && format[i + 1])
			{
				_putchar(format[i]);
				length++;
			}
			if (!found && !format[i + 1])
				length = -1;
/*FUNCTION 2*/
		}
	}
	return (length);
}

/*FUNCTION 2 move to here-> int found_percentage(int leng) - and then return leng for the length to be updated*/
