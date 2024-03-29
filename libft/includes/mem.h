/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:21:05 by gavizet           #+#    #+#             */
/*   Updated: 2018/04/24 13:58:09 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include "libft.h"

void				ft_memdel(void **ap);
void				free_tab2d(char ***tab);
void				*ft_memalloc(size_t size);
void				ft_exit_malloc_error(void);
void				ft_bzero(void *str, size_t len);
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memchr(const void *buffer, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

#endif
