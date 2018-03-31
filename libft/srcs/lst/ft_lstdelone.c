/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:31:23 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/13 21:16:57 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	t_list	*elem;

	elem = *alst;
	if (!elem)
		return ;
	else
	{
		del(elem->content, elem->content_size);
		free(elem);
	}
	*alst = NULL;
}
