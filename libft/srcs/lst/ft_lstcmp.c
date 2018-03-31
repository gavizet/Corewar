/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:06:27 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/03 16:14:01 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcmp(t_list **lst, char *str)
{
	t_list	*temp;

	temp = *lst;
	while (lst)
	{
		if ((ft_strcmp(str, temp->content)) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}
