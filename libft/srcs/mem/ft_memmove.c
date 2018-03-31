/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:14:33 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/09 17:22:44 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	if (src2 < dest2)
	{
		dest2 += n;
		src2 += n;
		while (n--)
			*--dest2 = *--src2;
	}
	else
	{
		while (n--)
			*dest2++ = *src2++;
	}
	return (dest);
}
