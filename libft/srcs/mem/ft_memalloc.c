/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:40:42 by gavizet           #+#    #+#             */
/*   Updated: 2017/06/08 16:16:52 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	if (size > 0)
	{
		new = malloc(size);
		if (new)
			ft_bzero(new, size);
	}
	return (new);
}
