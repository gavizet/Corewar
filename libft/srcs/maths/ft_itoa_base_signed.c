/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:17:44 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/17 18:02:05 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base_signed(ssize_t nbr, int base)
{
	char	*s;
	int		len;
	int		neg;
	ssize_t	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = nbr;
	neg = (base == 10 && nb < 0) ? 1 : 0;
	len = neg;
	while ((nbr /= base) != 0)
		len++;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	if (!nb)
		s[--len] = '0';
	while (nb != 0)
	{
		s[--len] = (nb > 0) ? HEXA[nb % base] : HEXA[(nb % base) * -1];
		nb /= base;
	}
	if (neg)
		s[--len] = '-';
	return (s);
}
