/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:11:17 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/17 16:56:34 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_len(ssize_t nb)
{
	int		len;

	len = 0;
	if (!nb)
		return (1);
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char		*ft_itoa(ssize_t nbr)
{
	char	*s;
	int		len;
	int		neg;

	neg = (nbr < 0) ? 1 : 0;
	len = ft_count_len(nbr) + neg;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	if (!nbr)
		s[--len] = '0';
	while (nbr != 0)
	{
		s[--len] = (!neg) ? (nbr % 10 + '0') : ((nbr % 10) * -1 + '0');
		nbr /= 10;
	}
	if (neg)
		s[--len] = '-';
	return (s);
}
