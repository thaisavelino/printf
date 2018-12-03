
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:02:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/30 15:04:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Loads a float type variable using va_arg() and ap.
**	Returns the number of printed characters.
*/

int		print_float(t_formatinfo *info, va_list ap)
{
	float	num;

	num = va_arg(ap, float);
}
