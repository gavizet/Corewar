/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:14:02 by rlangeoi          #+#    #+#             */
/*   Updated: 2018/04/15 19:54:48 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstrm(t_list **alst, t_list *prev)
{
	t_list *next;
	void	(*f)(void*, size_t);

	f = &ft_lstdelcontent;
	if (alst && *alst)
	{
		next = (*alst)->next;
		if (prev)
			prev->next = (*alst)->next;
		ft_lstdelone(alst, f);
		if (prev)
			(*alst) = prev;
		else
			(*alst) = next;
	}
}
