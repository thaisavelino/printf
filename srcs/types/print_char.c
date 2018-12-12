/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 13:35:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_formatinfo *info, va_list ap, t_output *output)
{
	(void)info;
	int		c;

	c = va_arg(ap, int);
	out_putchar(output, c);
}
