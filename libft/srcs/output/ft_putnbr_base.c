/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:28:06 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/13 15:42:33 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef HEXA
# define HEXA "0123456789ABCDEF"
#endif

void	ft_putnbr_base(int nb, int base)
{
	int	nbr;
	int	len;
	int	pow;
	int	neg;

	if (base < 2 || base > 16)
		return ;
	nbr = nb;
	neg = (nb < 0) ? 1 : 0;
	len = 0;
	pow = 1;
	if (neg)
		ft_putchar('-');
	while (nbr /= base)
		len++;
	while (len--)
		pow *= base;
	while (pow)
	{
		ft_putchar((nb < 0) ? HEXA[(nb / pow) * -1] : HEXA[nb / pow]);
		nb %= pow;
		pow /= base;
	}
}
