/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:15:39 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 22:27:37 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dest++ = *(unsigned char*)src++;
			return (dest);
		}
		*(unsigned char*)dest++ = *(unsigned char*)src++;
	}
	return (NULL);
}
