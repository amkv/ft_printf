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
# include "libft/libft.h"
# include <stdarg.h>

union			u_type
{
	char				*s;
	void				*p;
	int					d;
	unsigned int		o;
	long int			l;
	char				c;
	signed char			sc;
	short				sh;
	long				lo;
	long long			ll;
	intmax_t			it;
	unsigned char		uc;
	wchar_t				*ws;
	wchar_t				wc;
	unsigned short		us;
	unsigned long long	ull;
	unsigned long		ul;
	uintmax_t			ut;
	size_t				zu;
};

typedef struct	s_com
{
	char				*scroll;
	unsigned char		*w_scroll;
	size_t				len;
	char				type;
	char				*param;
	char				*flag;
	char				*width;
	int					width_flag;
	char				*precision;
	int					prec_flag;
	char				*length;
	char				*modifier;
	int					counter;
	union u_type		var;
	struct s_com		*next;
}				t_com;

/*
** Main functions
*/
int				ft_printf(const char *restrict format, ...);
void			ft_parser(const char *format, t_com **list);
void			ft_switch(char c, va_list ap, t_com **com);

/*
** Lists
*/
t_com			*ft_tcom_new(void);
void			ft_tcom_list(t_com **list, t_com *fresh);
void			ft_tcom_free_all(t_com *list);
void			ft_tcom_revert(t_com **list);

/*
** PARSER
*/
int				ft_pat_one(
				t_com **com, t_com **fresh, char **holder, size_t *yn);
char			*ft_pat_parameter(char **holder);
char			*ft_pat_flags(char **holder);
char			*ft_pat_width(char **holder);
char			*ft_pat_precision(char **holder);
char			*ft_pat_length(char **holder);
char			*ft_pat_modifier(char **holder);
void			ft_pat_ending(t_com **fresh, char **holder);
void			ft_pat_string(t_com **com, char **copy, char **holder);
int				ft_is_flag(char c);
int				ft_is_length(char c);
int				ft_is_modifier(char c);

/*
** DOs
*/
void			ft_do_s(char *str, t_com **com);
void			ft_do_ss(wchar_t *str, t_com **com);
void			ft_do_p(void *ptr, t_com **com);
void			ft_do_c(char c, t_com **com);
void			ft_do_cc(wchar_t c, t_com **com);
void			ft_do_d(int d, t_com **com);
void			ft_do_dd(long int d, t_com **com);
void			ft_do_d_h(short d, t_com **com);
void			ft_do_d_hh(signed char d, t_com **com);
void			ft_do_d_l(long d, t_com **com);
void			ft_do_d_ll(long long d, t_com **com);
void			ft_do_d_j(intmax_t d, t_com **com);
void			ft_do_d_z(size_t d, t_com **com);
void			ft_do_oux(unsigned int o, t_com **com, int base);
void			ft_do_oux_hh(unsigned char o, t_com **com, int base);
void			ft_do_oux_h(unsigned short o, t_com **com, int base);
void			ft_do_oux_ll(unsigned long long o, t_com **com, int base);
void			ft_do_oux_l(unsigned long o, t_com **com, int base);
void			ft_do_oux_j(uintmax_t o, t_com **com, int base);
void			ft_do_oux_z(size_t o, t_com **com, int base);
void			ft_do_oo(long int d, t_com **com);
void			ft_do_uu(long int u, t_com **com);

/*
** Pre print functions
*/
void			ft_pre_print_null_precision(t_com **fresh);
void			ft_pre_print_precision(t_com **com);
void			ft_pre_print_flags(t_com **com);
void			ft_pre_print_width(t_com **com);

/*
** Modifiers (scroll)
*/
void			ft_mod_add_spaces(t_com **com);
void			ft_mod_add_0x(t_com **com);
void			ft_mod_string_to_upper(char *str, t_com **com);
void			ft_mod_cut_word(t_com **com, size_t precision);
void			ft_mod_extend_word(t_com **com, size_t precision, size_t len);
void			ft_mod_add_sign(t_com **com);
void			ft_mod_add_zero(t_com **com);
void			ft_mod_add_one_space(t_com **com);

/*
** Addons
*/
void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_itoa_base_uintmax(uintmax_t value, uintmax_t base);
char			*ft_strdel_begn(char *str, size_t n);
void			ft_putstrn(const char *str, size_t n);
char			*ft_strnew_char_filled(size_t len, char c);
char			*ft_strdupn(const char *str, size_t n);
char			*ft_strjoin_and_free(char *str1, char *str2, int a, int b);
void			ft_free_and_set(char **old, char **new);
void			ft_putwstr(unsigned char *str);
size_t			ft_wcharlen(wchar_t wchar);
unsigned char	*wchar_str(wchar_t *str, unsigned int *length);
unsigned char	*wchar_chr(wchar_t chr, unsigned int *length);

#endif
