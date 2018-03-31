/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:41:02 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 20:15:21 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buffer, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)buffer == (unsigned char)c)
			return ((void*)buffer);
		buffer++;
	}
	return (NULL);
}
