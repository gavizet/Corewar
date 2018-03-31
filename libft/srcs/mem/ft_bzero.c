/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:49:15 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/08 18:01:26 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*dest;

	if (len == 0)
		return ;
	dest = (unsigned char*)str;
	while (len--)
		*dest++ = '0';
}
