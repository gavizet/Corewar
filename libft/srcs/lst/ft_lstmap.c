/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 00:43:42 by gavizet           #+#    #+#             */
/*   Updated: 2016/11/16 16:16:28 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*maillon;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(maillon = f(lst)))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp = f(lst)))
			return (NULL);
		ft_lstaddback(&maillon, tmp);
	}
	return (maillon);
}
