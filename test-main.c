#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int test_main(void)
{
/*
    unsigned int ui;
    void *addr;

    int len;
    int len2;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");


   _printf("%c\n", 'S');
    printf("%c\n", 'S');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');

*/
	int len1, len2;
   len1 = _printf("%%");
   len2 = printf("%%");
   printf("\nlength _printf: %i, length printf: %i\n", len1, len2);
   /* 
    _printf("\n");
    printf("\n");

    _printf("%K\n");
    printf("%K\n");
    _printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
    _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");

    _printf("Percent:[%K]\n");
    printf("Percent:[%K]\n");
   
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");

    _printf("Negative:[%d]\n", INT_MIN);
    printf("Negative:[%d]\n", INT_MIN);
    
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
   */
    return (0);
}
