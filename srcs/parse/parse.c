/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:15:24 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 17:49:13 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Parses the argument at the current position and strips the irrelevant flags.
*/

void		parse(const char *restrict format, int *format_pos, t_formatinfo *info)
{
	parse_flags(info, format, format_pos);
	parse_width(info, format, format_pos);
	parse_precision(info, format, format_pos);
	parse_length(info, format, format_pos);
	parse_specifier(info, format, format_pos);
	if (info->specifier != spec_int)
	{
		info->flags &= 0xff ^ FLAG_PLUS;
		info->flags &= 0xff ^ FLAG_SPACE;
	}
	if (info->flags & FLAG_HASPRECISION || info->flags & FLAG_MINUS)
	{
		info->flags &= 0xff ^ FLAG_ZERO;
	}
}
