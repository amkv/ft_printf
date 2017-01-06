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

/*
** удалить
** # include <stdio.h>
** void			ft_tcom_free_next(t_com **list);
** void			ft_tcom_free_first(t_com **list);
** void			ft_tcom_print(t_com *list, int yesno);
*/

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

//# pragma GCC diagnostic ignored "-Wunused-function"
//# pragma GCC diagnostic ignored "-Wunused-variable"
//# pragma GCC diagnostic ignored "-Wunused-parameter"
//# pragma GCC diagnostic ignored "-Wimplicitly-unsigned-literal"
//# pragma GCC diagnostic ignored "-Wformat"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

//# include <wchar.h>
//# include <wctype.h>

/*
**	# define CHAR_BIT 8
**	# define SCHAR_MIN -128
**	# define SCHAR_MAX 127
**	# define UCHAR_MAX 256
**	# define CHAR_MIN -128
**	# define CHAR_MAX 127
**	# define MB_LEN_MAX 16
**	# define SHRT_MIN -32768
**	# define SHRT_MAX 32767
**	# define USHRT_MAX 65535
**	# define INT_MIN -2147483648
**	# define INT_MAX 2147483647
**	# define UINT_MAX 4294967295
**	# define LONG_MIN -9223372036854775808
**	# define LONG_MAX 9223372036854775807
**	# define ULONG_MAX 18446744073709551615
*/

union			u_type
{
	char				*s;
	void				*p;
	int					d;
	int					i;
	unsigned int		o;
	unsigned int		u;
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

	float				f;
	double				db;
	long double			ldb;

};

/*
**	char				*scroll;	стринг для хранения вывода на печать
**	size_t				size;		не используется
**	size_t				len;		длина scroll
**	char				type;		% или .
**	void				*ptr;		не используется
**
**	char				*param;		n$ не используется
**	char				*flag;		- + space o # '
**	char				*width;		* или цифра
**	char				*precision;	* или .цифра
**	char				*length;	флаги hh h l ll z j t (L)bonus
**	char				*modifier;	sS p dD i oO uU xX cC &bonus eE fF gG aA n
**	int					counter;	счетчик количества листов
**	union u_type		var;		оригинальная переменная из стека ...
**
**	struct s_com		*next;		ссылка на сл.структуру
*/

typedef struct	s_com
{
	char				*scroll;
	unsigned char		*w_scroll;
	size_t				size;
	size_t				len;
	char				type;
	void				*ptr;
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
void			ft_parser(const char *format, t_com **list, size_t *argc);
void			ft_check_patterns(
				t_com **com, size_t *yn, char **holder, size_t *argc);
void			ft_switch(char c, va_list ap, t_com **com);

/*
** Lists
*/
t_com			*ft_tcom_new(void);
void			ft_tcom_list(t_com **list, t_com *fresh);
void			ft_tcom_free_all(t_com *list);
void			ft_tcom_revert(t_com **list);
void			ft_tcom_print(t_com *list, int yesno);
//void			ft_tcom_free_next(t_com **list);
//void			ft_tcom_free_first(t_com **list);

/*
** PARSER.
** patterns and checkers
*/
int				ft_pat_one(
				t_com **com, t_com **fresh, char **holder, size_t *yn);
char			*ft_pat_parameter(char **holder);
char			*ft_pat_flags(char **holder);
char			*ft_pat_width(char **holder);
char			*ft_pat_precision(char **holder);
char			*ft_pat_length(char **holder);
char			*ft_pat_modifier(char **holder);
void			ft_pat_ending(t_com **fresh, char **holder, size_t *argc);
void			ft_pat_string(t_com **com, char **copy, char **holder);

int				ft_is_flag(char c);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_modifier(char c);

/*
** Switch
*/

//void			ft_switch_d(va_list ap, t_com **com);
//void			ft_switch_oux(va_list ap, t_com **com, int base, int yesno);

/*
** DOs
*/
void			ft_do_s(char *str, t_com **com);
void			ft_do_ss(wchar_t *str, t_com **com);
void			ft_do_p(void *ptr, t_com **com);
void			ft_do_c(char c, t_com **com);
void			ft_do_cc(wchar_t c, t_com **com);
void			ft_do_d(int d, t_com **com);
void			ft_do_i(int d, t_com **com);
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

//void			ft_do_e(double f, t_com **com);
//void			ft_do_ee(double f, t_com **com);
//void			ft_do_f(double f, t_com **com);
//void			ft_do_ff(double f, t_com **com);
//void			ft_do_g(double f, t_com **com);
//void			ft_do_gg(double f, t_com **com);
//void			ft_do_a(double f, t_com **com);
//void			ft_do_aa(double f, t_com **com);
//void			ft_do_n(char *str, t_com **com);

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
unsigned char	*wchar_str(wchar_t *str, unsigned int *length);
unsigned char	*wchar_chr(wchar_t chr, unsigned int *length);

/*
** helpers
*/
void			ft_free_and_set(char **old, char **new);

/*
** Addons, которые можно использовать в других проектах
*/
char			*ft_strnncpy(char *dst, const char *src, size_t beg, size_t n);
void			*ft_memnncpy(void *dst, const void *src, size_t beg, size_t n);
long int		ft_numlen(long int num);
char			*ft_itoa_base(intmax_t value, intmax_t base);
char			*ft_itoa_base_uintmax(uintmax_t value, uintmax_t base);
char			*ft_strdel_begn(char *str, size_t n);
double			ft_pow(double x, double y);
void			ft_putstrn(const char *str, size_t n);
char			*ft_strnew_char_filled(size_t len, char c);
char			*ft_strdupn(const char *str, size_t n);
char			*ft_strjoin_and_free(char *str1, char *str2, int a, int b);

char			*ft_ftoa(double number, int length);

void			ft_putwstr(unsigned char *str);
size_t			ft_wstrlen(wchar_t *wstr);
size_t			ft_wcharlen(wchar_t wchar);

#endif
