/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlangeoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:35:40 by rlangeoi          #+#    #+#             */
/*   Updated: 2016/11/14 19:35:43 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list *alst, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (alst);
	while (i < n && alst->next)
	{
		alst = alst->next;
		i++;
	}
	if (i == n)
		return (alst);
	else
		return (NULL);
}
