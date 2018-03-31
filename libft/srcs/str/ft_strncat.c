/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:50:16 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/08 18:09:35 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s] && s < n)
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}
