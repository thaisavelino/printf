/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/30 15:43:37 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
*/

static int	print_arg(const char *restrict format, int *format_pos, va_list ap)
{
	t_formatinfo	formatinfo;

	if (format[(*format_pos) + 1] == '%')
	{
		ft_putchar('%');
		(*format_pos) += 2;
		return (1);
	}
	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse_flags(&formatinfo, format, format_pos);
	parse_width(&formatinfo, format, format_pos);
	parse_precision(&formatinfo, format, format_pos);
	parse_length(&formatinfo, format, format_pos);
	parse_specifier(&formatinfo, format, format_pos);
	return (print_arg_type(&formatinfo, ap));
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int	output_size;
	int	format_pos;

	va_start(ap, format);
	format_pos = 0;
	output_size = 0;
	while (format[format_pos] != '\0')
	{
		if (format[format_pos] == '%')
		{
			output_size += print_arg(format, &format_pos, ap);
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
