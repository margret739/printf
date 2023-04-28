#include "main.h"

/**
 * convert - converter function
 * @num: number
 * @base: base
 * @flag: argument flag
 * @param: parameter struct
 * Return: string
 */

char *convert(long int num, int base, int flag, param_t *param)

{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)param;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned int numbers
 * @ap: argument pointer
 * @param: prameter struct
 * Return: the bytes printed
 */

int print_unsigned(va_list ap, param_t *param)

{
	unsigned int long l;

	if (param->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	param->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, param), param));
}

/**
 * print_address - prints address
 * @ap: argument pointer
 * @param: parameter struct
 * Return: bytes printed
 */

int print_address(va_list ap, param_t *param)

{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, param));
}
