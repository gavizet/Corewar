/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:48:48 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/13 15:42:39 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int nb)
{
	int		nbr;
	int		len;
	int		pow;
	int		neg;

	nbr = nb;
	neg = (nb < 0) ? 1 : 0;
	len = 0;
	pow = 1;
	if (neg)
		ft_putchar('-');
	while (nbr /= 10)
		len++;
	while (len--)
		pow *= 10;
	while (pow)
	{
		ft_putchar((nb < 0) ? ((nb / pow) * -1 + '0') : (nb / pow) + '0');
		nb %= pow;
		pow /= 10;
	}
}
