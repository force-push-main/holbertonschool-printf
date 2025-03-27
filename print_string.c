#include "main.h"

int print_string(va_list arg)
{

	char *str = va_arg(arg, char*);
	int j;
	int char_count = 0;
	
	if (str == NULL)
	{
		str = "(null)";
	}
	for (j = 0; str[j] != '\0'; j++)
	{
		_putchar(str[j]);
		char_count++;
	}

	return (char_count);
}
