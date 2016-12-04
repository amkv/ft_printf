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

void 	ft_test(char *str, t_com **com)
{
	char 	*temp;
	char 	*result;
	char 	*copy;

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
	free((*com)->command);
	(*com)->command = result;
	(*com)->len = ft_strlen(result);
}

void		ft_resize_string(char *str, t_com **com)
{
	free((*com)->command);
	(*com)->command = ft_strdup(str);
	(*com)->len = ft_strlen(str);
}

void		ft_char_bla(char c, t_com **com)
{
	free((*com)->command);
	(*com)->command = ft_strnew(2);
	*(*com)->command = c;
	*((*com)->command + 1) = '\0';
	(*com)->len = ft_strlen((*com)->command);
}

void		ft_int_bla(int d, t_com **com)
{
	free((*com)->command);
//	(*com)->command = ft_strnew((size_t)ft_numlen(d) + 1);
	(*com)->command = ft_itoa(d);
	(*com)->len = ft_strlen((*com)->command);
}
