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

//void			ft_pre_print_length(t_com **com)
//{
//	return ;
//}

void			ft_pre_print_flags(t_com **com)
{
	if ((*com)->flag == NULL)
		return ;
	if (*(*com)->flag == '_')
		ft_flags_minus(*&com);
	if (*(*com)->flag == '+')
		ft_flags_plus(*&com);
//	if (*(*com)->flag == ' ')
//		ft_flags_space(*&com);
	if (*(*com)->flag == '#')
		ft_flags_octo(*&com);
//	if (*(*com)->flag == '0')
//		ft_flags_zero(*&com);
}

void			ft_pre_print_precision(t_com **com)
{
	if (!(*com)->precision)
		return ;
	size_t 		precision;
	size_t		len;

	precision = (size_t)ft_atoi((*com)->precision);
	len = (*com)->len;
	if (precision == len || len == 0)
		return ;
	else if (precision < len)
		ft_mod_cut_word(*&com, precision);
	else if (precision > len)
		ft_mod_extend_word(*&com, precision, len);
}

void			ft_pre_print_width(t_com **com)
{
	if ((*com)->width)
		ft_mod_add_spaces(*&com);
}
