/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:43:08 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/11 11:40:24 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	save;

	i = 0;
	size = 0;
	while (str[size] != '\0')
		size++;
	size = size - 1;
	while (i < size)
	{
		save = str[size];
		str[size] = str[i];
		str[i] = save;
		i++;
		size--;
	}
	return (str);
}
