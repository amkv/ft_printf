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
//# pragma GCC diagnostic ignored "-Wformat"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

//# include <wchar.h>
//# include <wctype.h>

/*
** # include <stdio.h> // delete
** void			ft_tcom_print(t_com *list); // fot tests only
*/

# define CHAR_BIT 8
# define SCHAR_MIN -128
# define SCHAR_MAX 127
# define UCHAR_MAX 256
# define CHAR_MIN -128
# define CHAR_MAX 127
# define MB_LEN_MAX 16
# define SHRT_MIN -32768
# define SHRT_MAX 32767
# define USHRT_MAX 65535
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define UINT_MAX 4294967295
# define LONG_MIN -9223372036854775808
# define LONG_MAX 9223372036854775807
# define ULONG_MAX 18446744073709551615

union			u_type
{
	char			*s;			// OK
	void			*p;			// OK (pointer)
	int				d;			// OK
	int				i; 			// OK (d)
	unsigned int	o; 			// OK (base 8)
	unsigned int	u;			// OK
	long int		l;			//
	char			c;			//

	signed char		sc;			// hh
	short			sh;			// h
	long 			lo;
	long long		ll;
	intmax_t 		it;
//	ptrdiff_t		pt;

	unsigned char	ac;

	unsigned short	ush;
	unsigned long	ul;
	float			f;
	double			db;
	long double		ldb;
	size_t			zu;
};

typedef struct	s_com
{
	char			*scroll;	// стринг для хранения вывода на печать
	size_t			size;		// не используется
	size_t			len;		// длина scroll
	char			type;		// % или .
	void			*ptr;		// не используется

	char			*param;		// n$ не используется
	char			*flag;		// - + space o # '
	char			*width;		// * или цифра
	char			*precision;	// * или .цифра
	char			*length;	// флаги hh h l ll z j t (L)bonus
	char 			*modifier;	// sS p dD i oO uU xX cC &bonus eE fF gG aA n
	int				counter;	// счетчик количества листов
	union u_type	var;		// оригинальная переменная из стека ...

	struct s_com	*next;		// ссылка на сл.структуру
}				t_com;

/*
** Main functions
*/
int				ft_printf(const char *restrict format, ...);
void			ft_parser(const char *format, t_com **list, size_t *argc);
void			ft_check_patterns(t_com **com, size_t *yn, char **holder, size_t *argc);

/*
** Switch
*/
void			ft_switch(char c, va_list ap, t_com **com);
void			ft_switch_d(va_list ap, t_com **com);

/*
** Lists
*/
t_com			*ft_tcom_new(void);
void			ft_tcom_list(t_com **list, t_com *fresh);
void			ft_tcom_free_all(t_com *list);
void			ft_tcom_free_next(t_com **list);
void			ft_tcom_free_first(t_com **list);
void			ft_tcom_print(t_com *list, int yesno);
void			ft_tcom_revert(t_com **list);

/*
** PARSER.
** patterns and chekers
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

int				ft_is_flag(char c);
int				ft_is_precision(char c);
int				ft_is_length(char c);
int				ft_is_modifier(char c);
/*
** DOs
*/
void			ft_do_s(char *str, t_com **com);			//mandatory s
void			ft_do_ss(char *str, t_com **com);			//mandatory S	//не сделано
void			ft_do_p(void *ptr, t_com **com);			//mandatory p

void			ft_do_d(int d, t_com **com);				//mandatory d
void			ft_do_dd(long int d, t_com **com);			//mandatory D	//не сделано
void			ft_do_d_h(short d, t_com **com);
void			ft_do_d_hh(signed char d, t_com **com);
void            ft_do_d_l(long d, t_com **com);
void			ft_do_d_ll(long long d, t_com **com);
void			ft_do_d_j(intmax_t d, t_com **com);
void			ft_do_d_z(size_t d, t_com **com);

void			ft_do_i(int d, t_com **com);				//mandatory i
void			ft_do_o(unsigned int d, t_com **com);		//mandatory o
void			ft_do_oo(unsigned int d, t_com **com);		//mandatory O	// не сделано
void			ft_do_u(unsigned int d, t_com **com);		//mandatory u
void			ft_do_uu(unsigned int d, t_com **com);		//mandatory U	// не сделано
void			ft_do_x(long long num, t_com **com);		//mandatory x
void			ft_do_xx(unsigned int num, t_com **com);	//mandatory X
void			ft_do_c(char c, t_com **com);				//mandatory c
void			ft_do_cc(char c, t_com **com);				//mandatory C	// не сделано

void			ft_do_e(double f, t_com **com);				//bonus		e	// не сделано
void			ft_do_ee(double f, t_com **com);			//bonus		E	// не сделано
void			ft_do_f(double f, t_com **com);				//bonus		f
void			ft_do_ff(double f, t_com **com);			//bonus		F	// не сделано
void			ft_do_g(double f, t_com **com);				//bonus		g	// не сделано
void			ft_do_gg(double f, t_com **com);			//bonus		G	// не сделано
void			ft_do_a(double f, t_com **com);				//bonus		a	// не сделано
void			ft_do_aa(double f, t_com **com);			//bonus		A	// не сделано
void			ft_do_n(char *str, t_com **com);			//bonus		n	// не сделано

/*
** Flags
*/
void			ft_flags_octo(t_com **com);
void			ft_flags_zero(t_com **com);
void			ft_flags_minus(t_com **com);
void			ft_flags_plus(t_com **com);
void			ft_flags_space(t_com **com);

/*
** Pre print functions
*/
void			ft_pre_print(t_com **com);
void			ft_pre_print_precision(t_com **com);
void			ft_pre_print_flags(t_com **com);
void			ft_pre_print_width(t_com **com);

/*
** Modifiers (scroll)
*/
void			ft_mod_add_spaces(t_com **com);
void			ft_mod_add_0x(t_com **com);
void			ft_string_to_upper(char *str, t_com **com);
void			ft_mod_cut_word(t_com **com, size_t precision);
void 			ft_mod_extend_word(t_com **com, size_t precision, size_t len);
void			ft_mod_add_sign(t_com **com);

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
char		    *ft_itoa_base(long long value, long long base);
char			*ft_strdel_begn(char *str, size_t n);
char			*ft_ftoa(double number, int length);
double			ft_pow(double x, double y);
void			ft_putstrn(const char *str, size_t n);
char 			*ft_strnew_spaces(size_t len, char c);
char 			*ft_strdupn(const char *str, size_t n);

#endif
