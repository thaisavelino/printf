/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:02:25 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/05 16:04:05 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen(long long num, int base_len)
{
	int total;

	total = 1;
	if (num < 0)
	{
		num *= -1;
		total++;
	}
	while ((num /= base_len) > 0)
		total++;
	return (total);
}
