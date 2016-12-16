/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:00 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/09 16:46:02 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			ft_pre_print(t_com **com)
{
	ft_pre_print_precision(*&com);
	ft_pre_print_flags(*&com);
	ft_pre_print_width(*&com);
	return ;
}

void			ft_pre_print_flags(t_com **com)
{
	if ((*com)->flag == NULL)
		return ;
	if (*(*com)->flag == '_')
		ft_flags_minus(*&com);
	if (*(*com)->flag == '+')
		ft_flags_plus(*&com);
	if (*(*com)->flag == ' ')
		ft_flags_space(*&com);
	if (*(*com)->flag == '#')
		ft_flags_octo(*&com);
	if (*(*com)->flag == '0')
		ft_flags_zero(*&com);
}

void			ft_pre_print_precision(t_com **com)
{
	char		*result;
	size_t 		len;
	size_t 		str_len;

	if ((*com)->precision != NULL && *(*com)->modifier != 'd'
			&& *(*com)->modifier != 'x')
	{
		len = (size_t)ft_atoi((*com)->precision);
		str_len = ft_strlen((*com)->scroll);
		if (len >= str_len)
			return ;
		result = ft_strnew(str_len + 1);
		ft_memcpy(result, (*com)->scroll, len);
		free((*com)->scroll);
		(*com)->scroll = NULL;
		(*com)->scroll = result;
		(*com)->len = len;

	}
}

void			ft_pre_print_width(t_com **com)
{
	char		*result;

	if ((*com)->width)
	{
		result = ft_add_spaces((*com)->scroll, (*com)->width);
		free((*com)->scroll);
		(*com)->scroll = result;
		(*com)->len = ft_strlen(result);
	}
}
