/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:17 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/29 15:00:24 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	while (to_find[i] == str[i] && to_find[i] && str[i])
		i++;
	if (to_find[i] == '\0')
		return (1);
	return (0);
}

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	if (!(to_find[i]))
		return ((char*)str);
	while (str[i])
	{
		if ((str[i] == to_find[0]) && (find(&str[i], to_find)))
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
