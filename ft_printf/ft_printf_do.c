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
	char 	*str;
	size_t 	pointer;
	size_t 	len;

	pointer = (size_t)&ptr;
	len = (size_t)ft_numlen(pointer);
	str = (ft_strnew(len));
	str = ft_itoa((int)pointer);
	(*com)->scroll = str;
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

void		ft_resize_string(char *str, t_com **com)
{
	(*com)->scroll = ft_strdup(str);
	(*com)->len = ft_strlen(str);
}
