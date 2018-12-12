/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prepound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:50:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 19:03:22 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the specified prepound string if needed.
*/

void	print_prepound(t_formatinfo *info, char *str, va_list ap, t_output *output)
{
	t_u64	num;
	va_list	ap2;

	if (!(info->flags & FLAG_PREPOUND))
		return;
	va_copy(ap2, ap);
	num = read_argument_unsigned(info, ap2);
	if (num != 0 || info->specifier == spec_octal)
		out_putchar_len(output, str, ft_strlen(str));
}
