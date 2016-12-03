/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:13:45 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/24 13:24:39 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h> // delete

typedef struct	s_com
{
	char			type;
	char			*command;
	size_t			len;
	struct s_com	*next;
}				t_com;

int				ft_printf(const char *restrict format, ...);
int				ft_numlen(int num);
int				ft_is_flag(char c);
int				ft_is_width(char c);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_type(char c);
void			ft_parser(const char *format, t_com **list, size_t *arg);
t_com			*ft_tcom_new(char type, char *command);
void			ft_tcom_add(t_com **beg, t_com *next);
void			ft_tcom_free(t_com *list);
void			ft_tcom_print(t_com *list); // fot tests only
void			*ft_tcom_revert(t_com **list);

char			*ft_strnncpy(char *dst, const char *src, size_t start, size_t len);
void			*ft_memnncpy(void *dst, const void *src, size_t start, size_t n);

//int		ft_atoi_base(char *str, char *base);

#endif
