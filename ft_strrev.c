/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:51:06 by tavelino          #+#    #+#             */
/*   Updated: 2018/11/30 17:22:10 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	strrev(char *str)
{
	char	swap;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	len--;
	while ((str[i] != '\0') && (i < (len / 2)))
	{
		swap = str[len];
		str[len] = str[i];
		str[i] = swap;
		i++;
	}
}
