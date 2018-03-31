/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:18:31 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 16:49:17 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f) (char))
{
	size_t		i;
	char		*cpy;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = f(s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
