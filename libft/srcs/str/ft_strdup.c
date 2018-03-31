/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:49:41 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/09 02:07:32 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dest;

	if (!(dest = (char*)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
