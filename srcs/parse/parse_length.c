/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:02 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/06 16:53:09 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_length(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	char		*str;
	t_length	len;

	str = (char*)format + (*format_pos);
	if (!ft_strncmp(str, "hh", 2))
		len = len_char;
	else if (!ft_strncmp(str, "h", 1))
		len = len_short;
	else if (!ft_strncmp(str, "ll", 2))
		len = len_llong;
	else if (!ft_strncmp(str, "l", 1))
		len = len_long;
	else
		return ;
	if (len == len_char || len == len_llong)
		(*format_pos) += 2;
	else if (len == len_long || len == len_short)
		(*format_pos) += 1;
	info->length = len;
}
