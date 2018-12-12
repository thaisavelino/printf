/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:03 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/06 16:52:07 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	while (format[*format_pos] != '\0')
	{
		if (format[*format_pos] == '#')
			info->flags |= FLAG_PREPOUND;
		else if (format[*format_pos] == '0')
			info->flags |= FLAG_ZERO;
		else if (format[*format_pos] == '+')
			info->flags |= FLAG_PLUS;
		else if (format[*format_pos] == '-')
			info->flags |= FLAG_MINUS;
		else if (format[*format_pos] == ' ')
			info->flags |= FLAG_SPACE;
		else
			return ;
		(*format_pos)++;
	}
}
