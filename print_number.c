#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: character to check
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)

{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns length of a string
 * @s: string length to check
 * Return: integer length of a string
 */

int _strlen(char *s)

{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints number with options
 * @str: base of a string
 * @param: parameter struct
 * Return: chars printed
 */

int print_number(char *str, param_t *param)

{
	unsigned int i = _strlen(str);
	int neg = (!param->unsign && *str == '-');
	
	if (!param->precision && *str == '0' && !str[i])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (param->precision != UINT_MAX)
		while (i++ < param->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!param->minus_flag)
		return (print_number_right_shift(str, param));
	else
		return (print_number_left_shift(str, param));
}

/**
 * print_number_right_shift - prints a number with option
 * @str: the base number as a string
 * @param: the parameter struct
 * Return: char printed
 */

int print_number_right_shift(char *str, param_t *param)

{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (param->zero_flag && !param->minus_flag)
		pad_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pad_char == '0' && !param->minus_flag)
		str++;
	else
		neg = 0;
	if ((param->plus_flag && !neg2) ||
		(!param->plus_flag && param->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (param->plus_flag && !neg2 && pad_char == '0' && !param->unsign)
		n += _putchar('+');
	else if (!param->plus_flag && param->space_flag && !neg2 &&
			!param->unsign && param->zero_flag)
		n += _putchar(' ');
	while (i++ < param->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (param->plus_flag && !neg2 && pad_char == ' ' && !param->unsign)
		n += _putchar('+');
	else if (!param->plus_flag && param->space_flag && !neg2 &&
			!param->unsign && !param->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints number with options
 * @str: base of string
 * @param: parameter struct
 * Return: chars printed
 */

int print_number_left_shift(char *str, param_t *param)

{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (param->zero_flag && !param->minus_flag)
		pad_char = '0';
	neg = neg2 = (!param->unsign && *str == '-');
	if (neg && i < param->width && pad_char == '0' && !param->minus_flag)
		str++;
	else
		neg = 0;

	if (param->plus_flag && !neg2 && !param->unsign)
		n += _putchar('+'), i++;
	else if (param->space_flag && !neg2 && !param->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < param->width)
		n += _putchar(pad_char);
	return (n);
}
