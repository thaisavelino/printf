/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:51:12 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/06 16:51:14 by juazouz          ###   ########.fr       */
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
