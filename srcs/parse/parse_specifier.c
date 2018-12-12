/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:22 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 17:48:18 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_specifier(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	char		c;
	t_specifier	spec;

	c = format[*format_pos];
	if (c == 'i' || c == 'd')
		spec = spec_int;
	else if (c == 'u')
		spec = spec_uint;
	else if (c == 'x')
		spec = spec_hex;
	else if (c == 'X')
		spec = spec_hexup;
	else if (c == 'o')
		spec = spec_octal;
	else if (c == 'f' || c == 'F')
		spec = spec_float;
	else if (c == 's')
		spec = spec_str;
	else if (c == 'c')
		spec = spec_char;
	else if (c == 'p')
	{
		spec = spec_hex;
		info->flags |= FLAG_PREPOUND;
	}
	else if (c == '%')
		spec = spec_percent;
	else
	{
		ft_putstr("ft_printf error: Unknown specifier: ");
		ft_putchar(c);
		ft_putendl("");
		exit(EXIT_FAILURE);
	}
	(*format_pos)++;
	info->specifier = spec;
}
