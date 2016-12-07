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
# include <stdio.h>
# define PLEN 10

/*
** # include <stdio.h> // delete
** void			ft_tcom_print(t_com *list); // fot tests only
*/

typedef struct	s_com
{
	char			type;
	char			param[PLEN];
	char			flag[PLEN];
	char			width[PLEN];
	char			precision[PLEN];
	char			length[PLEN];
	char			*command;
	char			*scroll;
	void			*ptr;
	size_t			size;
	size_t			len;
	struct s_com	*next;
}				t_com;

union			u_type
{
	char			c;
	unsigned char	ac;
	signed char		sc;
	int				d;
	unsigned int	ui;
	short			sh;
	unsigned short	ush;
	long			l;
	unsigned long	ul;
	float			f;
	double			db;
	long double		ldb;
	char			*s;
	void			*p;
	size_t			zu;
};

int				ft_printf(const char *restrict format, ...);
int				ft_is_flag(char c);
int				ft_is_width(char c);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_type(char c);
void			ft_parser(const char *format, t_com **list, size_t *argc);
t_com			*ft_tcom_new(char type, char *command);
void			ft_tcom_add(t_com **beg, t_com *next);
void			ft_tcom_free(t_com *list);
void			ft_tcom_print(t_com *list);
t_com			*ft_tcom_revert(t_com **list);
void			ft_switch(char c, union u_type *type, va_list ap, t_com **com);

/*
** Addons
*/

char			*ft_strnncpy(char *dst, const char *src, size_t beg, size_t n);
void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
int				ft_numlen(int num);
char 			*ft_itoa_base(int value, int base);

/*
** DOs
*/
void			ft_do_S(char *str, t_com **com);
void			ft_resize_string(char *str, t_com **com);
void			ft_do_c(char c, t_com **com);
void			ft_do_d(int d, t_com **com);
void			ft_do_p(void *ptr, t_com **com);

/*
** int			ft_atoi_base(char *str, char *base);
** void			ft_print_pointer(void *ptr, t_com **com);
*/

#endif
