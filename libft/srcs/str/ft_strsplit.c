/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:57:40 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 18:28:28 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_words(const char *str, char c)
{
	int wds;

	if (!(*str))
		return (0);
	while (*str == c)
	{
		str++;
		if (*str == '\0')
			return (0);
	}
	wds = 1;
	while (*str != '\0')
	{
		if (*str == c)
		{
			while (*(str + 1) == c)
				str++;
			wds++;
		}
		str++;
	}
	if (*(str - 1) == c)
		wds--;
	return (wds);
}

static int		ft_wordlen(const char *str, char c)
{
	int i;

	i = 1;
	while (*str != c && *str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		wds;
	int		i;
	char	**supercool;

	if (!(s))
		exit(EXIT_FAILURE);
	wds = ft_words(s, c);
	if (!(supercool = (char**)malloc(sizeof(char*) * (wds + 1))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < wds)
	{
		while (*s == c)
			s++;
		supercool[i] = ft_strsub(s, 0, (ft_wordlen(s, c) - 1));
		i++;
		while (*s != c && *s != '\0')
			s++;
	}
	supercool[i] = 0;
	return (supercool);
}
