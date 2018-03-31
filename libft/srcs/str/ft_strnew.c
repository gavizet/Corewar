/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:30:15 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/13 15:03:32 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	if (!(tab = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size)
	{
		tab[size] = '\0';
		size--;
	}
	tab[size] = '\0';
	return (tab);
}
