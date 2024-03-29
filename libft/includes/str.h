/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:21:29 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 13:59:12 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strrev(char *str);
int					ft_strisint(char *nbr);
char				*ft_strnew(size_t size);
int					ft_wstrlen(wchar_t *str);
int					ft_str_isdigit(char *str);
size_t				ft_strlen(const char *str);
char				*ft_strtrim(char const *s);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *str, int n);
char				*ft_strrchr(const char *str, int n);
char				**ft_strsplit(char const *s, char c);
void				ft_striter(char *s, void (*f) (char *));
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
int					ft_calc_wstrlen(wchar_t *str, int precision, int i);

#endif
