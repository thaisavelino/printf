/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:06:45 by tavelino          #+#    #+#             */
/*   Updated: 2018/11/30 19:10:46 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_convertnbr_base(int nbr, char* base, int base_len, char **str)
{

	if (nbr < 0)
	{
		**str = '-';
		(*str)++;
		nbr = -nbr;
	}
	if (nbr > base_len)
	{
		//recursive
		ft_convertnbr_base((nbr / base_len), base, base_len, str);
	}
	// else
	// 	str[1] = '\0';
	**str = base[(nbr % base_len)];
	(*str)++;
}



int	ft_putnbr_base(size_t nbr, char *base)
{
	int len;
	char str[50];
	char	*str2;

	str2 = str;
	len = ft_strlen(base);
	ft_bzero(str, sizeof(str));
	ft_convertnbr_base(nbr, base, len, &str2);
	//ft_strrev(str); //need to make a function to reverse before print ft_strrev.c
	ft_putstr(str);
	return (str2 - str); // return size
}
