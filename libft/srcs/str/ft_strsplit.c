/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:57:40 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/16 12:45:01 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_tab(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	nb_tab(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s[i] == c))
		j = 1;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				j++;
			i++;
		}
		i++;
	}
	return (j);
}

static char	*copy_tab(char *dest, char const *src, int s, char c)
{
	int		d;

	d = 0;
	if (!src[s])
		return (NULL);
	while (src[s])
	{
		if (src[s] != c && src[s] != '\0')
			dest[d] = src[s];
		else
			return (dest);
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}

static char	*find_tab(char const *src, char c, int n_mot)
{
	char	*cpy;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!(cpy = (char*)malloc(sizeof(char) * (len_tab((char*)src, c) + 1))))
		return (NULL);
	while (src[i] && src[i] == c)
		i++;
	while (count < n_mot)
	{
		while (src[i] && src[i] != c)
			i++;
		while (src[i] == c && src[i])
			i++;
		count++;
	}
	return (copy_tab(cpy, src, i, c));
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_t;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	nb_t = nb_tab(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_t + 1))))
		return (NULL);
	while (count < nb_t)
	{
		tab[count] = find_tab(s, c, count);
		count++;
	}
	tab[count] = NULL;
	return (tab);
}
