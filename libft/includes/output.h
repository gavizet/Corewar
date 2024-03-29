/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:20:58 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 13:59:27 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include "libft.h"

void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_base(int nb, int base);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putwchar(wchar_t str);
int					ft_putnwstr(const wchar_t *str, int len);

#endif
