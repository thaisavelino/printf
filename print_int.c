/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:08:48 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/05 16:07:05 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE10 "012345679"

// static function to protect
static long long		ft_casting_num(t_formatinfo *info,  va_list ap)
{
	long long	num;

	if (info->length == len_char)
		num = (signed char)(va_arg(ap, int));
	else if (info->length == len_short)
		num = (short)(va_arg(ap, int));
	else if (info->length == len_llong)
		num = (long long)(va_arg(ap, long long int));
	else if (info->length == len_long)
		num = (long)(va_arg(ap, long int));
	else
		num = (int)(va_arg(ap, int));
	return (num);
}

int			print_int(t_formatinfo *info, va_list ap)
{
	long long  	num;
	int			nbrlen;

	num = ft_casting_num(info, ap);
	nbrlen = ft_nbrlen(num, 10);
	ft_putnbr_base(num, BASE10);
	return (0);
}
