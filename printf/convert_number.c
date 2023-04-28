#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @param: the parameter struct
 * Return: bytes printed
 */

int print_hex(va_list ap, param_t *param)

{
	unsigned long l;
	int c = 0;
	char *str;

	if (param->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	if (param->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += print_number(str, param));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: argument pointer
 * @param: parameter struct
 * Return: bytes printed
 */

int print_HEX(va_list ap, param_t *param)

{
	unsigned long l;
	int c = 0;
	char *str;

	if (param->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, param);
	if (param->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	param->unsign = 1;
	return (c += print_number(str, param));
}

/**
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @param: parameter struct
 * Return: bytes printed
 */

int print_binary(va_list ap, param_t *param)

{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, param);
	int c = 0;

	if (param->hashtag_flag && n)
		*--str = '0';
	param->unsign = 1;
	return (c += print_number(str, param));
}

/**
 * print_octal - prints unsigned octal number
 * @ap: argument pointer
 * @param: parameter struct
 * Return: bytes printed
 */

int print_octal(va_list ap, param_t *param)

{
	unsigned long l;
	char *str;
	int c = 0;

	if (param->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (param->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, param);

	if (param->hashtag_flag && l)
		*--str = '0';
	param->unsign = 1;
	return (c += print_number(str, param));
}
