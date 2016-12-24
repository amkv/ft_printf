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

/*
** ******* switch *******************************************
*/

void			ft_pre_print(t_com **com)
{
	ft_pre_print_precision(*&com);
	ft_pre_print_flags(*&com);
	ft_pre_print_width(*&com);
	return ;
}

/*
** ******* pre print flags *******************************************
*/

void			ft_pre_print_flags(t_com **com)
{
	char		*flags;

	if (!(flags = (*com)->flag))
		return ;
	while (*flags)
	{
		if (*flags == '_')
			ft_mod_add_spaces(*&com);
		if (*flags == '+')
			ft_mod_add_sign(*&com);
		if (*flags == ' ')
			ft_mod_add_one_space(*&com);
		if (*flags == '#')
			ft_mod_add_0x(*&com);
		if (*flags == '0')
			ft_mod_add_zero(*&com);
		flags++;
	}
}

/*
** ******* pre print precision *******************************************
*/

void			ft_pre_print_precision(t_com **com)
{
	size_t		precision;
	size_t		len;

	if (!(*com)->precision)
		return ;
	if ((*com)->modifier && (*com)->var.c != 0
		&& (*(*com)->modifier == 'c' || *(*com)->modifier == 'C'))
	{
		*(*com)->scroll = '*';
		*(*com)->modifier = 's';
		return ;
	}
	precision = (size_t)ft_atoi((*com)->precision);
	len = (*com)->len;
	if (precision == 0 || ((*com)->modifier
		&& *(*com)->modifier == 's' && *(*com)->modifier == 'S'))
		return ;
	else if ((*com)->scroll && *(*com)->scroll == '\0')
		return ;
	else if ((*com)->modifier && *(*com)->modifier == 'p' && precision < len)
		return ;
	else if ((*com)->modifier && (*(*com)->modifier == 'u' || *(*com)->modifier == 'U') && precision < len)
		return ;
	else if ((*com)->modifier && *(*com)->modifier == 's' && precision >= len)
		return ;
	else if ((*com)->modifier && (*(*com)->modifier == 'o' || *(*com)->modifier == 'O') && precision < len)
		return ;
	else if (precision < len)
		ft_mod_cut_word(*&com, precision);
	else if (precision > len)
		ft_mod_extend_word(*&com, precision, len);
}

/*
** ******* pre print width *******************************************
*/

void			ft_pre_print_width(t_com **com)
{
	intmax_t	width;
	size_t		len;
	size_t		new_width;

	if ((*com)->width)
	{
		width = ft_atoi((*com)->width);
		if (width < 0)
		{
			new_width = (size_t)-width;
			len = (*com)->len;
			if (new_width > len)
				(*com)->len = (size_t)new_width;
			return ;
		}
		else
			ft_mod_add_spaces(*&com);
	}
}

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
			(*(*com)->scroll == '0' ||
					((*com)->modifier && *(*com)->modifier == 's')
			))
	{
		if (!(*(*com)->modifier))
			return ;
		else if (*(*com)->modifier == 's')
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
		else if (*(*com)->modifier == 'i')
			ft_pre_print_null_precision_helper(*&com);
	}
}
