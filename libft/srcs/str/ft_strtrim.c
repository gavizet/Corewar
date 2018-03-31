/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:42:26 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 18:10:59 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	len;
	int	start;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	start = i;
	i = ft_strlen((char*)s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i--;
	len = i - start + 1;
	return (ft_strsub(s, start, len));
}
