/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:26:29 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/13 21:16:49 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem)
	{
		next = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
