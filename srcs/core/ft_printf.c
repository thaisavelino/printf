/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 10:57:29 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
*/

static int	parse_and_print_argument(const char *restrict format, int *format_pos, va_list ap)
{
	t_formatinfo	formatinfo;

	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse(format, format_pos, &formatinfo);
	return (print_argument(&formatinfo, ap));
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		output_size;
	int		format_pos;

	va_start(ap, format);
	format_pos = 0;
	output_size = 0;
	while (format[format_pos] != '\0')
	{
		if (format[format_pos] == '%')
		{
			format_pos++;
			output_size += parse_and_print_argument(format, &format_pos, ap);
		}
		else
		{
			ft_putchar(format[format_pos]);
			format_pos++;
			output_size++;
		}
	}
	va_end(ap);
	return (output_size);
}
