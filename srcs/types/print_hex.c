/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 18:56:46 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"0123456789abcdef"
#define BASE_LEN	16
#define PREPOUND	"0x"

void		print_hex(t_formatinfo *info, va_list ap, t_output *output)
{
	print_prepound(info, PREPOUND, ap, output);
	print_number_generic(info, ap, BASE, output);
}
