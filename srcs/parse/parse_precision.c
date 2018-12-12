/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:40 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 15:49:51 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_precision(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	if (format[*format_pos] == '.')
	{
		(*format_pos)++;
		info->precision = parse_number(format, format_pos);
		info->flags |= FLAG_HASPRECISION;
	}
}
