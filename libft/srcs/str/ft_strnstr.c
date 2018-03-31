/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:50:54 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/12 10:57:23 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nfind(char const *str, char const *to_find, size_t n)
{
	int		i;

	i = 0;
	while (to_find[i] == str[i] && n--)
		i++;
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	stock;

	i = 0;
	if (!(to_find[i] || n == 0))
		return ((char*)str);
	while (str[i] && i < n)
	{
		if ((str[i] == to_find[0]) && (nfind(&str[i], to_find, n)))
		{
			stock = i + ft_strlen(to_find);
			if (n >= stock)
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
