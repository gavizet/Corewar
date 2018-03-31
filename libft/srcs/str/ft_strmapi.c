/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:59:20 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/08 23:33:40 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	if (!s)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
