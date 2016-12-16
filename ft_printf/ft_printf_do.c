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

void				ft_do_s(char *str, t_com **com)
{
	char			*result;

	result = ft_strdup(str);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(str);
}

void				ft_do_ss(char *str, t_com **com)
{
	char			*temp;
	char			*result;
	char			*copy;

	temp = str;
	result = ft_strnew(ft_strlen(str) + 1);
	if (result == NULL)
		return ;
	copy = result;
	while (*temp)
	{
		*copy = (char)ft_toupper(*temp);
		copy++;
		temp++;
	}
	*copy = '\0';
//	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_p(void *ptr, t_com **com)
{
	char			*str;
	char			*result;
	long int		pointer;

	pointer = (long int)*&ptr;
	str = ft_itoa_base(pointer, 16);
	result = ft_strjoin("0x", str);
	free(str);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_d(int d, t_com **com)
{
	(*com)->scroll = ft_itoa(d);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_dd(int d, t_com **com) // не готова
{
	(*com)->scroll = ft_itoa(d);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_i(int d, t_com **com) // не готова
{
	(*com)->scroll = ft_itoa(d);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_o(unsigned int d, t_com **com)
{
	char			*result;

	result = ft_itoa_base(d, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_oo(unsigned int d, t_com **com) // не готова
{
	char			*result;

	result = ft_itoa_base(d, 8);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void				ft_do_u(unsigned int d, t_com **com)
{
	char			*result;

	result = ft_itoa_base(d, 10);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_uu(unsigned int d, t_com **com)
{
	char			*result;

	result = ft_itoa_base(d, 10);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_x(int num, t_com **com)
{
	char			*result;
	long int		number;

	if (num >= 0)
	{
		result = ft_itoa_base(num, 16);
		(*com)->scroll = result;
		(*com)->len = ft_strlen(result);
	}
	if (num < 0)
	{
		number = 4294967295 - (-num) + 1;
		result = ft_itoa_base(number, 16);
		(*com)->scroll = result;
		(*com)->len = ft_strlen(result);
	}
}

void				ft_do_xx(int num, t_com **com)
{
	ft_do_x(num, *&com);
	ft_do_ss((*com)->scroll, *&com);
}

void				ft_do_c(char c, t_com **com)
{
	char			*result;

	result = ft_strnew(2);
	result[0] = c;
	result[1] = '\0';
	free((*com)->scroll);
	(*com)->len = 1;
	(*com)->scroll = result;
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
	multi = ft_itoa(index - 1);
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
