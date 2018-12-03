/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:31:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/30 15:38:28 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Selects the right function to print the argument.
**	Returns the number of printed characters.
*/

int		print_arg_type(t_formatinfo *formatinfo, va_list ap)
{
	int			(*f[SPEC_COUNT])(t_formatinfo*, va_list);
	int			(*print_func)(t_formatinfo*, va_list);
	t_specifier	spec;

	f[spec_int] = print_int;
	f[spec_uint] = print_uint;
	f[spec_octal] = print_octal;
	f[spec_hex] = print_hex;
	f[spec_hexup] = print_hexup;
	f[spec_float] = print_float;
	f[spec_str] = print_str;
	f[spec_char] = print_char;
	spec = formatinfo->specifier;
	print_func = f[spec];

	return (print_func(formatinfo, ap));
}
