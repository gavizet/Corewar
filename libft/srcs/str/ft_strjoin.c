/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:40 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/21 20:17:54 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		d;
	int		i;
	char	*cpy;

	d = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char) *
					((ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1)))))
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[d])
	{
		cpy[i] = s2[d];
		d++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
