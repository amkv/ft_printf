/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:22:19 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:21 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
		if (*flags == '-')
			;
		else if (*flags == '+')
			ft_mod_add_sign(*&com);
		else if (*flags == ' ')
			ft_mod_add_one_space(*&com);
		else if (*flags == '#')
			ft_mod_add_0x(*&com);
		else if (*flags == '0')
		{
			if (ft_strchr_qt(flags, '-') > 0)
				;
			else
				ft_mod_add_zero(*&com);
		}
		flags++;
	}
}

/*
** ******* plus flag *********************************************************
*/

void			ft_mod_add_sign(t_com **com)
{
	char		*result;

	if (!(*com)->scroll && !(*com)->modifier)
		return ;
	if ((*com)->modifier && (*(*com)->modifier == 'd' || *(*com)->modifier == 'i'))
	{
		if (ft_atoi((*com)->scroll) < 0)
			return ;
		else
		{
			result = ft_strjoin("+", (*com)->scroll);
			ft_free_and_set(&(*com)->scroll, &result);
			(*com)->len += 1;
		}
	}
}

/*
** ****** zero flag ***********************************************************
*/

void			ft_mod_add_zero(t_com **com)
{
	char		*mod;
	char 		*zeros;
	char		*result;
//	char 		*temp;
	size_t 		width;

	if (!(mod = (*com)->modifier))
		return ;
	if ((*com)->precision || ((*mod == 'd' || *mod == 'D' || *mod == 'i'
		|| *mod == 'o' || *mod == 'O' || *mod == 'u' || *mod == 'U'
		|| *mod == 'x' || *mod == 'X')) || !(*com)->width)
		return ;
	width = (size_t)ft_atoi((*com)->width);
	zeros = NULL;
	if (width > (*com)->len)
		zeros = ft_strnew_char_filled(width - (*com)->len, '0');
	if (width <= (*com)->len)
		zeros = ft_strdup("");
	if (*mod == 'p')
		result = ft_strjoin((*com)->scroll, zeros);
//	else if ((*com)->scroll && *(*com)->scroll == '-')
//	{
//		temp = ft_strdel_begn((*com)->scroll, 1);
//		free((*com)->scroll);
//		(*com)->scroll = ft_strjoin("-", zeros);
//		result = ft_strjoin((*com)->scroll, temp);
//		free(temp);
//	}
	else
	{
		if (!(*com)->scroll)
			(*com)->scroll = ft_strnew(1);
		result = ft_strjoin(zeros, (*com)->scroll);
	}
	ft_free_and_set(&(*com)->scroll, &result);
	free(zeros);
	if (*mod == 'c')
		(*com)->len = width;
	else if (*mod == 'S')
		(*com)->len = width;
	else
		(*com)->len = ft_strlen((*com)->scroll);
	free((*com)->width);
	(*com)->width = NULL;
}

/*
** ****** space flag (one space)*********************************************
*/

void 			ft_mod_add_one_space(t_com **com)
{
	char 		*result;
	char		*mod;

	if (!(mod = (*com)->modifier))
		return ;
	if (*mod == 'd' || *mod == 'D' || *mod == 'i')
	{
		if ((*com)->var.d < 0)
			return ;
		else if (ft_strchr_qt((*com)->flag,'+') > 0)
			return ;
		else if ((*com)->scroll && *(*com)->scroll == '+')
			return ;
		else
		{
			result = ft_strjoin(" ", (*com)->scroll);
			ft_free_and_set(&(*com)->scroll, &result);
			(*com)->len += 1;
		}
	}
}

/*
** ************* # flag ****************************************
*/

static int		ft_add_0x_helper(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'n' || c == 'p' ||
		c == 's' || c == 'u')
		return (1);
	return (0);
}

void			ft_mod_add_0x(t_com **com)
{
	char		*beg;
	char		*result;

	if (!(*com)->scroll || ft_atoi((*com)->scroll) == 0 ||
		!(*com)->modifier || ft_add_0x_helper(*(*com)->modifier) == 1)
		return ;
	else if (*(*com)->modifier == 'x')
		beg = ft_strdup("0x");
	else if (*(*com)->modifier == 'X')
		beg = ft_strdup("0X");
	else if (*(*com)->modifier == 'o')
		beg = ft_strdup("0");
	else if (*(*com)->modifier == 'O')
		beg = ft_strdup("0");
	else
		return ;
	if ((*com)->precision && ft_atoi((*com)->precision) > 0
		&& (*(*com)->modifier == 'o' || *(*com)->modifier == 'O'))
	{
		beg = ft_strdup("");
		result = ft_strjoin(beg, (*com)->scroll);
	}
	else
		result = ft_strjoin(beg, (*com)->scroll);
	free(beg);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}
