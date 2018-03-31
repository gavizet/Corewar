/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:51:05 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/16 17:20:45 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int n)
{
	char	*save;

	save = 0;
	if ((unsigned char)n == '\0')
	{
		while (*str)
			str++;
		save = (char*)(str++);
		return (save);
	}
	while (*str)
	{
		if (*str == (char)n)
			save = (char*)str;
		str++;
	}
	return ((save != 0) ? save : NULL);
}
