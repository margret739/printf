#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: format string
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list ap, param_t *param)

{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s ==  specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - find the format function
 * @s: string
 * @ap: argument pointer
 * @param: parameter struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list ap, param_t *param)

{
	int (*f)(va_list, param_t *) = get_specifier(s);

	if (f)
		return (f(ap, param));
	return (0);
}

/**
 * get_flag - find the flag function
 * @s: string
 * @param: the parameter struct
 * Return: flag is valid
 */

int get_flag(char *s, param_t *param)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = param->plus_flag = 1;
			break;
		case ' ':
			i = param->space_flag = 1;
			break;
		case '%':
			i = param->hashtag_flag = 1;
			break;
		case '-':
			i = param->minus_flag = 1;
			break;
		case '0':
			i = param->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - find modifier function
 * @s: format string
 * @param: parameter struct
 * Return: if modifier was valid
 */

int get_modifier(char *s, param_t *param)

{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = param->h_modifier = 1;
			break;
		case 'l':
			i = param->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets width from format string
 * @s: string
 * @param: parameter struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, param_t *param, va_list ap)

{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	param->width = d;
	return (s);
}
