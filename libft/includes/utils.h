/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:29:48 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 17:52:31 by rlangeoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# define BUFF_SIZE 16

int					ft_islower(int c);
int					ft_isalpha(int n);
int					ft_isdigit(int n);
int					ft_isalnum(int n);
int					ft_isascii(int n);
int					ft_isprint(int n);
int					ft_toupper(int n);
int					ft_tolower(int n);
int					ft_isupper(int nb);
void				ft_error(char *error);
void				ft_swap(void **a, void **b);
int					ft_isdigitstr(const char *str);
int					get_next_line(const int fd, char **line);

#endif
