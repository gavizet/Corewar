/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 11:00:21 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/15 19:14:30 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int		line_contains_label_char(char *str)
{
	int		i;

	i = 0;
	while (is_empty_char(str[i]))
		i++;
	while ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)
			|| str[i] == '_')
		i++;
	if (str[i] == LABEL_CHAR)
		return (i);
	return (0);
}

int		stock_line(t_asm *file, char *str, int line_nb)
{
	int		line_contains_label;
	char	**split_line;

	line_contains_label = line_contains_label_char(str) ? 1 : 0;
	if (!line_contains_label)
	{
		if (!init_line(file, LINE_TYPE_INSTRU, str, line_nb))
			return (-1);
	}
	else
	{
		//ft_printf("TEST LABEL 1 \n");
		split_line = ft_strsplit(str, LABEL_CHAR);
		if (!init_line(file, LINE_TYPE_LABEL, split_line[0], line_nb))
			return (-1);
		//ft_printf("TEST LABEL 2 \n");
		if (!line_is_empty(split_line[1]))
		{
			//ft_printf("TEST LABEL 3 \n");
			if (!init_line(file, LINE_TYPE_INSTRU, split_line[1],
					line_nb))
			{
				free_tab2d(&split_line);
				return (-1);
			}
		}
		free_tab2d(&split_line);
	}
	return (1);
}

int		stock_file(t_asm *file, int fd)
{
	char	*str;
	int		line_nb;

	str = NULL;
	line_nb = 0;
	while (get_next_line(fd, &str))
	{
		if (str && *str && !line_is_empty(str) && line_is_comment(str))
		{
			if (!stock_line(file, str, line_nb))
				return (-1);
			line_nb++;
		}
		ft_strdel(&str);
	}
	return (1);
}
