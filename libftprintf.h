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

/*
** # include <stdio.h> // delete
** void			ft_tcom_print(t_com *list); // fot tests only
*/

typedef struct	s_com
{
	char			*scroll;
	size_t			size;
	size_t			len;
	char			type;
	void			*ptr;

	char			*param;
	char			*flag;
	char			*width;
	char			*precision;
	char			*length;
	char 			*modifier;


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

char 			*ft_pat_parameter(char **holder);
int				ft_is_flag(char c);
char			*ft_pat_width(char **holder);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_modifier(char c);
char 			*ft_pat_string(char **holder);

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
long int		ft_numlen(long int num);
char			*ft_itoa_base(long int value, long int base);
char 			*ft_strdel_begn(char *str, size_t n);

/*
** DOs
*/
void			ft_do_S(char *str, t_com **com);
void			ft_do_s(char *str, t_com **com);
void			ft_do_c(char c, t_com **com);
void			ft_do_d(int d, t_com **com);
void			ft_do_x(int num, t_com **com);
void			ft_do_X(int num, t_com **com);
void			ft_do_p(void *ptr, t_com **com);

/*
** int			ft_atoi_base(char *str, char *base);
** void			ft_print_pointer(void *ptr, t_com **com);
*/

void	ft_second_check(t_com **com, char **holder, size_t *yn);


void		ft_nothing(void);

#endif
