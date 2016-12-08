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

void		ft_do_p(void *ptr, t_com **com)
{
	char 			*str;
	char 			*result;
	long int		pointer;

	pointer = (long int)*&ptr;
	str = ft_itoa_base(pointer, 16);
	result = ft_strjoin("0x", str);
	free(str);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void		ft_do_x(int num, t_com **com)
{
	char 	*result;
//	unsigned int	revers;
//	unsigned int	number;
//
//	if (num >= 0)
//		number = (unsigned int)num;
//	else
//	{
//		revers = 4294967295;
//		num = -(num);
//		number = revers - num;
//
//	}
	result = ft_itoa_base(num, 16);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void		ft_do_X(int num, t_com **com)
{
	char 	*result;

//	if (num < 0)
//		num = -(num);
	result = ft_itoa_base(num, 16);
	ft_do_S(result, *&com);
	free(result);
}

void		ft_do_S(char *str, t_com **com)
{
	char	*temp;
	char	*result;
	char	*copy;

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
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

void		ft_do_c(char c, t_com **com)
{
	(*com)->scroll = ft_strnew(2);
	*(*com)->scroll = c;
	*((*com)->scroll + 1) = '\0';
	(*com)->len = 1;
}

void		ft_do_d(int d, t_com **com)
{
	(*com)->scroll = ft_itoa(d);
	(*com)->len = ft_strlen((*com)->scroll);
}

void		ft_do_s(char *str, t_com **com)
{
	(*com)->scroll = ft_strdup(str);
	(*com)->len = ft_strlen(str);
}
