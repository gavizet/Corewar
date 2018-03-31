/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:29:13 by gavizet           #+#    #+#             */
/*   Updated: 2017/01/20 13:52:27 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **liste)
{
	t_list	*actual;
	t_list	*suivant;

	suivant = *liste;
	if (*liste)
	{
		suivant = suivant->next;
		(*liste)->next = NULL;
		while (suivant)
		{
			actual = suivant;
			suivant = suivant->next;
			actual->next = *liste;
			*liste = actual;
		}
	}
}
