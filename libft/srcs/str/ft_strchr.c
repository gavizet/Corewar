/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:49:20 by gavizet           #+#    #+#             */
/*   Updated: 2017/03/22 15:12:31 by argirin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == '\0')
	{
		while (*str != (char)c && *str)
			str++;
		return ((char*)str);
	}
	while (*str != (char)c && *str)
		str++;
	return (*str == '\0' ? NULL : (char*)str);
}
