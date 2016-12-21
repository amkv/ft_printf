/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:07:44 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/03 21:07:45 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** o modifier **************************************************************
*/

void				ft_do_o(unsigned int o, t_com **com)
{
	char			*result;

	result = ft_itoa_base(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_hh(unsigned char o, t_com **com)
{
	char			*result;

	result = ft_itoa_base(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_h(unsigned short o, t_com **com)
{
	char			*result;

	result = ft_itoa_base(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_ll(unsigned long long o, t_com **com)
{
	char			*result;

	result = ft_itoa_base_uintmax(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_l(unsigned long o, t_com **com)
{
	char			*result;

	result = ft_itoa_base_uintmax(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_j(uintmax_t o, t_com **com)
{
	char			*result;

	result = ft_itoa_base_uintmax(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_o_z(size_t o, t_com **com)
{
	char			*result;

	result = ft_itoa_base_uintmax(o, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_oo(long int d, t_com **com)
{
//	free((*com)->scroll);
//	(*com)->scroll = ft_itoa_base(d, 8);
//	(*com)->len = ft_strlen((*com)->scroll);
	ft_do_o_l((unsigned long int)d, *&com);
}

/*
** u modifier **************************************************************
*/

void				ft_do_u(unsigned int u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_uu(long int u, t_com **com)
{
//	free((*com)->scroll);
//	(*com)->scroll = ft_itoa_base(u, 10);
//	(*com)->len = ft_strlen((*com)->scroll);
	ft_do_u_l((unsigned long) u, *&com);
}

void			ft_do_u_hh(unsigned char u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_u_h(unsigned short u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_u_ll(unsigned long long u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base_uintmax(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_u_l(unsigned long u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base_uintmax(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_u_j(uintmax_t u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base_uintmax(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_u_z(size_t u, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base_uintmax(u, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

/*
** x modifier **************************************************************
*/

void				ft_do_x(long long x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_hh(unsigned char x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_h(unsigned short x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_ll(unsigned long long x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_l(unsigned long x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_j(uintmax_t x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_x_z(size_t x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

/*
** xx modifier **************************************************************
*/

void				ft_do_xx(unsigned int x, t_com **com)
{
	ft_do_x(x, *&com);
	ft_string_to_upper((*com)->scroll, *&com);
}

void			ft_do_xx_hh(unsigned char x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_xx_h(unsigned short x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_xx_ll(unsigned long long x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_xx_l(unsigned long x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_xx_j(uintmax_t x, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

void			ft_do_xx_z(size_t x, t_com **com)
{	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_itoa_base_uintmax(x, 16);
	(*com)->len = ft_strlen((*com)->scroll);
}

/*
** c modifier **************************************************************
*/

void				ft_do_c(char c, t_com **com)
{
//	free((*com)->scroll);
//	(*com)->scroll = NULL;
	(*com)->scroll = ft_strnew(1);
	(*com)->len = 1;
}

/*
** Bonus part **************************************************************
*/

void				ft_do_e(double number, t_com **com)
{
	char			*num_string;
	int				index;
	char			*multi;
	char			*temp;

	index = 0;
//	if (number < 0)
//		number = -number;
	num_string = ft_ftoa(number, 10);
	while (num_string[index] != '\0')
	{
		if (num_string[index] == '.')
			break ;
		index++;
	}
	multi = ft_itoa_base(index - 1, 10);
	while (index != 1)
	{
		num_string[index] = num_string[index - 1];
		index--;
	}
	num_string[1] = '.';
	temp = ft_strjoin(num_string, "e+0");
	free(num_string);
	num_string = ft_strjoin(temp, multi);
	free(temp);
	free(multi);
	free((*com)->scroll);
	(*com)->scroll = num_string;
	(*com)->len = ft_strlen(num_string);
	/*
 переписать полностью
	int 	left;
	double	right;
	char 	*result;
	char 	len;
	char 	minus[2];
	int 	length;
//
	length = 6;
//	length = (*com)->precision;
	minus[0] = '-';
	minus[1] = '\0';
	len = 0;
	if (number < 0)
	{
		number = -number;
		len++;
	}
	else
		minus[0] = '\0';
	left = (int)number;
	right = number - (double)left;
	if (left == 0)
		right = right * ft_pow(10, length);
*/
}

void				ft_do_ee(double f, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}

void				ft_do_f(double f, t_com **com)
{
	(*com)->scroll = ft_ftoa(f, 6);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_ff(double f, t_com **com)
{
	(*com)->scroll = ft_ftoa(f, 6);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_g(double f, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}

void				ft_do_gg(double f, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}

void				ft_do_a(double f, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}

void				ft_do_aa(double f, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}

void				ft_do_n(char *str, t_com **com)
{
	(*com)->scroll = NULL;
	(*com)->len = 0;
}
