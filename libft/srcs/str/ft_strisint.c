/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:44:08 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 14:01:09 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_return(char *int_min, char *int_max, int ret)
{
	free(int_min);
	free(int_max);
	return (ret);
}

int		ft_strisint(char *nbr)
{
	int		i;
	char	*int_min;
	char	*int_max;

	i = -1;
	int_min = ft_itoa(INT_MIN);
	int_max = ft_itoa(INT_MAX);
	if ((nbr[0] != '-' && ft_strlen(nbr) < ft_strlen(int_max)) ||
			(nbr[0] == '-' && ft_strlen(nbr) < ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 1));
	else if ((nbr[0] != '-' && ft_strlen(nbr) > ft_strlen(int_max)) ||
			(nbr[0] == '-' && ft_strlen(nbr) > ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 0));
	if (nbr[0] == '-' && ++i + 1)
		while (nbr[++i] != '\0')
			if (nbr[i] > int_min[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[0] != '-')
		while (nbr[++i] != '\0')
			if (nbr[i] > int_max[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[i] == '\0')
		return (ft_return(int_min, int_max, 1));
	return (ft_return(int_min, int_max, 0));
}
