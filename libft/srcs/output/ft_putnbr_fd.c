/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:42:17 by gavizet           #+#    #+#             */
/*   Updated: 2016/12/13 15:04:07 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long int	stock;

	stock = n;
	if (stock < 0)
	{
		ft_putchar_fd('-', fd);
		stock = -stock;
	}
	if (stock < 10)
		ft_putchar_fd(stock + '0', fd);
	if (stock >= 10)
	{
		ft_putnbr_fd(stock / 10, fd);
		ft_putnbr_fd(stock % 10, fd);
	}
}
