#include "main.h"

/**
 * init_param - clears struct field and resets buf
 * @ap: argument pointer
 * @param: the parameter struct
 * return: void
 */

void init_param(param_t *param, va_list ap)

{
	param->unsign = 0;

	param->plus_flag = 0;
	param->space_flag = 0;
	param->hashtag_flag = 0;
	param->zero_flag = 0;
	param->minus_flag = 0;

	param->width = 0;
	param->precision = UINT_MAX;

	param->h_modifier = 0;
	param->l_modifier = 0;
	(void)ap;
}
