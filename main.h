#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAM_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: if plus_flag specified
 * @space_flag: if _flag specified
 * @hashtag_flag: if _flag specified
 * @zero_flag: if_flag specified
 * @minus_flag: if _flag specified
 *
 * @width: field width specicified
 * @precision: precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */

typedef struct parameters

{
	unsigned int unsign        : 1;

	unsigned int plus_flag     : 1;
	unsigned int space_flag    : 1;
	unsigned int hashtag_flag  : 1;
	unsigned int zero_flag     : 1;
	unsigned int minus_flag    : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier    : 1;
	unsigned int l_modifier    : 1;
} param_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f : function associated
 */

typedef struct specifier

{
	char *specifier;
	int (*f) (va_list, param_t *);
} specifier_t;

/*_put.c module */
int _puts(char *str);
int _putchar(int c);

/*print_functions.c module*/
int print_char(va_list ap, param_t *param);
int print_int(va_list ap, param_t *param);
int print_string(va_list ap, param_t *param);
int print_percent(va_list ap, param_t *param);
int print_S(va_list ap, param_t *param);

/*number.c module*/
char *convert(long int num, int base, int flags, param_t *param);
int print_unsigned(va_list ap, param_t *param);
int print_address(va_list ap, param_t *param);

/*specifier.c module*/
int (*get_specifier(char *s))(va_list ap, param_t *param);
int get_print_func(char *s, va_list ap, param_t *param);
int get_flag(char *s, param_t *param);
int get_modifier(char *s, param_t *param);
char *get_width(char *s, param_t *param, va_list ap);

/*convert_number.c module*/
int print_hex(va_list ap, param_t *param);
int print_HEX(va_list ap, param_t *param);
int print_binary(va_list ap, param_t *param);
int print_octal(va_list ap, param_t *param);

/*simple_printers.c module*/
int print_from_to(char *start, char *stop, char *exc);
int print_rev(va_list ap, param_t *param);
int print_rot13(va_list ap, param_t *param);

/*print_number.c module*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, param_t *param);
int print_number_right_shift(char *str, param_t *param);
int print_number_left_shift(char *str, param_t *param);

/*param.c module*/
void init_param(param_t *param, va_list ap);

/*string_field.c module*/
char *get_precision(char *p, param_t *param, va_list ap);

/*_printf.c*/
int _printf(const char *format, ...);

#endif
