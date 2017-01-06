/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:51:06 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:51:07 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ******* pre print null precision *******************************************
*/

static void		ft_pre_print_null_precision_helper(t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	if (*(*com)->modifier == 'p')
	{
		(*com)->scroll = ft_strdup("0x");
		(*com)->len = 2;
	}
	else if (*(*com)->modifier == 'S')
	{
		(*com)->scroll = ft_strdup("");
		(*com)->len = 0;
		*(*com)->modifier = 's';
	}
	else
	{
		(*com)->scroll = ft_strdup("");
		(*com)->len = 0;
	}
	free((*com)->precision);
	(*com)->precision = NULL;
}

void			ft_pre_print_null_precision(t_com **com)
{
	if ((*com)->precision && *(*com)->precision == '!' &&
		(((*com)->scroll && *(*com)->scroll == '0') ||
		 ((*com)->modifier &&
		  (*(*com)->modifier == 's' || *(*com)->modifier == 'S'))
		))
	{
		if (!(*(*com)->modifier))
			return ;
		else if (*(*com)->modifier == 's' || *(*com)->modifier == 'i')
			ft_pre_print_null_precision_helper(*&com);
		else if (*(*com)->modifier == 'S')
			ft_pre_print_null_precision_helper(*&com);
		else if ((*(*com)->modifier == 'x' || *(*com)->modifier == 'X')
				 && ft_strchr_qt((*com)->flag, '#') > 0)
			ft_pre_print_null_precision_helper(*&com);
		else if (*(*com)->modifier == 'x' || *(*com)->modifier == 'X')
			ft_pre_print_null_precision_helper(*&com);
		else if ((*(*com)->modifier == 'o' || *(*com)->modifier == 'O')
				 && ft_strchr_qt((*com)->flag, '#') == 0)
			ft_pre_print_null_precision_helper(*&com);
		else if ((*(*com)->modifier == 'd' || *(*com)->modifier == 'D'))
			ft_pre_print_null_precision_helper(*&com);
		else if ((*(*com)->modifier == 'u' || *(*com)->modifier == 'U'))
			ft_pre_print_null_precision_helper(*&com);
		else if ((*(*com)->modifier == 'p' || *(*com)->modifier == 'P')
				 && (*com)->len == 3)
			ft_pre_print_null_precision_helper(*&com);
	}
}
