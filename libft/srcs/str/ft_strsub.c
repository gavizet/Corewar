/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:58:00 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/17 18:00:02 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cpy[i] = s[start];
		i++;
		start++;
	}
	cpy[i] = '\0';
	return (cpy);
}
