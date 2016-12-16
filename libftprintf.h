/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:13:45 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/10 20:58:19 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# pragma GCC diagnostic ignored "-Wunused-function"
# pragma GCC diagnostic ignored "-Wunused-variable"
# pragma GCC diagnostic ignored "-Wunused-parameter"
# pragma GCC diagnostic ignored "-Wformat"

# include "libft/libft.h"
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
	unsigned int 	uo;
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

/*
** Main functions
*/
int				ft_printf(const char *restrict format, ...);
void			ft_parser(const char *format, t_com **list, size_t *argc);
void			ft_switch(char c, union u_type *type, va_list ap, t_com **com);
void			ft_check_patterns(t_com **com, size_t *yn, char **holder, size_t *argc);

/*
** Lists
*/
t_com			*ft_tcom_new(void);
void			ft_tcom_list(t_com **list, t_com *fresh);
void			ft_tcom_free_all(t_com *list);
void			ft_tcom_free_next(t_com **list);
void			ft_tcom_free_first(t_com **list);
void			ft_tcom_print(t_com *list);
void			ft_tcom_revert(t_com **list);

/*
** ft_is chekers
*/
int				ft_is_flag(char c);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_modifier(char c);

/*
** PARSER.
** patterns
*/
int				ft_pat_one(t_com **com, t_com **fresh, char **holder, size_t *yn);
char			*ft_pat_parameter(char **holder);
char			*ft_pat_flags(char **holder);
char			*ft_pat_width(char **holder);
char			*ft_pat_precision(char **holder);
char			*ft_pat_length(char **holder);
char			*ft_pat_modifier(char **holder);
void			ft_pat_ending(t_com **fresh, char **holder, size_t *argc);
void			ft_pat_string(t_com **com, char **copy, char **holder);

/*
** DOs
*/
void			ft_do_s(char *str, t_com **com);
void			ft_do_ss(char *str, t_com **com);			// не сделано
void			ft_do_c(char c, t_com **com);
void			ft_do_d(int d, t_com **com);
void			ft_do_x(int num, t_com **com);
void			ft_do_xx(int num, t_com **com);
void			ft_do_p(void *ptr, t_com **com);
void			ft_do_u(unsigned int d, t_com **com);		// не сделано
void			ft_do_uu(unsigned int d, t_com **com);
void			ft_do_o(unsigned int d, t_com **com);
void			ft_do_f(double f, t_com **com);
void			ft_do_ff(double f, t_com **com);			// не сделано
void			ft_do_e(double f, t_com **com);				// не сделано
void			ft_do_ee(double f, t_com **com);			// не сделано
void			ft_do_g(double f, t_com **com);				// не сделано
void			ft_do_gg(double f, t_com **com);			// не сделано
void			ft_do_a(double f, t_com **com);				// не сделано
void			ft_do_aa(double f, t_com **com);			// не сделано
void			ft_do_n(char *str, t_com **com);			// не сделано

/*
** Modifiers
*/
char			*ft_add_spaces(char *str, char *width);

/*
** Flags
*/
void			ft_flags_minus(t_com **com);
void			ft_flags_plus(t_com **com);
void			ft_flags_space(t_com **com);
void			ft_flags_octo(t_com **com);
void			ft_flags_zero(t_com **com);

/*
** Pre print functions
*/
void			ft_pre_print(t_com **com);
void			ft_pre_print_precision(t_com **com);
void			ft_pre_print_flags(t_com **com);
void			ft_pre_print_width(t_com **com);

/*
** Addons
*/
char			*ft_strnncpy(char *dst, const char *src, size_t beg, size_t n);
void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
long int		ft_numlen(long int num);
char			*ft_itoa_base(long int value, long int base);
char			*ft_strdel_begn(char *str, size_t n);
char			*ft_ftoa(double number, int length);
double			ft_pow(double x, double y);

/*
** helpers
*/
void			ft_free_and_set(char **old, char **new);

void	ft_nothing(void);

#endif
