/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:05:41 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/17 16:49:14 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		ft_putstr("room [");
		ft_putnbr(tmp->content_size);
		ft_putstr("] == ");
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}
