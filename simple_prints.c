#include "main.h"

/**
 * print_from_to - prints a range of char address
 * @start: starting address
 * @stop: stopping address
 * @ex: except address
 * Return: number of bytes printed
 */

int print_from_to(char *start, char *stop, char *exc)

{
	int sum = 0;

	while (start <= stop)
	{
		if (start != exc)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @param: parameter struct
 * Return: number of bytes printed
 */

int print_rev(va_list ap, param_t *param)

{
	int len, sum = 0;
	char *str = va_arg(ap, char*);
	(void)param;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - print string in rot13
 * @ap: string
 * @param: parameter struct
 * Return: number of bytes printed
 */

int print_rot13(va_list ap, param_t *param)

{
	int d, ind;
	int count = 0;
	char arr[] =
		"MNOPQRSTUVWXYZABCDEFGHIJKL    mnopqrstuvwxyzabcdefghijkl";
	char *a = va_arg(ap, char *);
	(void)param;

	d = 0;
	ind = 0;
	while (a[d])
	{
		if ((a[d] >= 'A' && a[d] <= 'Z')
			|| (a[d] >= 'a' && a[d] <= 'z'))
		{
			ind = a[d] - 65;
			count += _putchar(arr[ind]);
		}
		else
			count += _putchar(a[d]);
		d++;
	}
	return (count);
}
