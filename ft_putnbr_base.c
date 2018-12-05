/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:06:45 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/05 16:03:11 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void		ft_convertnbr_base(long long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > base_len)
	{
		ft_convertnbr_base((nbr / base_len), base, base_len);
	}
	ft_putchar(base[(nbr % base_len)]);
}

int			ft_putnbr_base(long long nbr, char *base)
{
	int		base_len;
	int		output_len;

	base_len = ft_strlen(base);
	ft_convertnbr_base(nbr, base, base_len);
	return (output_len);
}
