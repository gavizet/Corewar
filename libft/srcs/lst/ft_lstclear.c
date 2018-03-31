/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:25:57 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/26 16:34:47 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **liste)
{
	t_list	*elem;

	elem = *liste;
	while (elem)
	{
		*liste = elem->next;
		free(elem);
		elem = *liste;
	}
	*liste = NULL;
}
