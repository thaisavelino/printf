/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:15:24 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/30 15:44:10 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_number(const char *restrict format, int *format_pos)
{
	int	digit;
	int	res;

	res = 0;
	while (ft_isdigit(format[*format_pos]))
	{
		digit = format[*format_pos] - '0';
		res *= 10;
		res += digit;
		(*format_pos)++;
	}
	return (res);
}

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

void		parse_width(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	info->width = parse_number(format, format_pos);
}

void		parse_precision(t_formatinfo *info, const char *restrict format, int *format_pos)
{
	if (format[*format_pos] == '.')
	{
		(*format_pos)++;
		info->precision = parse_number(format, format_pos);
	}
}

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
	else
		exit(EXIT_FAILURE);

	info->specifier = spec;
}
