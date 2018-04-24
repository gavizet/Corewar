/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 19:46:07 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/24 18:29:39 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstrm_at(t_list **alst, int nb)
{
	t_list	*cur;
	t_list	*prev;
	int		i;

	i = 0;
	cur = (*alst);
	prev = NULL;
	while (++i < nb && cur)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur)
	{
		if (prev)
			prev->next = cur->next;
		else if (nb == 1)
			(*alst) = cur->next;
		ft_lstdelone(&cur, &ft_lstdelcontent);
	}
}
