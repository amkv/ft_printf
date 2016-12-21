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

//void				ft_do_ee(double f, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
//
//void				ft_do_f(double f, t_com **com)
//{
//	(*com)->scroll = ft_ftoa(f, 6);
//	(*com)->len = ft_strlen((*com)->scroll);
//}
//
//void				ft_do_ff(double f, t_com **com)
//{
//	(*com)->scroll = ft_ftoa(f, 6);
//	(*com)->len = ft_strlen((*com)->scroll);
//}
//
//void				ft_do_g(double f, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
//
//void				ft_do_gg(double f, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
//
//void				ft_do_a(double f, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
//
//void				ft_do_aa(double f, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
//
//void				ft_do_n(char *str, t_com **com)
//{
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//}
