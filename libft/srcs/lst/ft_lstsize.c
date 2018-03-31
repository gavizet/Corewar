/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:22:15 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/26 16:34:13 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_lstsize(t_list *begin_list)
{
	t_list		*elem;
	size_t		i;

	i = 0;
	if (!begin_list)
		return (i);
	elem = begin_list;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
