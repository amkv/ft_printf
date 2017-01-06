/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:02:55 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:02:57 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
** + flag
*/

void			ft_mod_add_sign(t_com **com)
{
	char		*result;

	if (!(*com)->scroll && !(*com)->modifier)
		return ;
	if ((*com)->modifier && (*(*com)->modifier == 'd'
						|| *(*com)->modifier == 'i'))
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
** space flag (one space)
*/

void			ft_mod_add_one_space(t_com **com)
{
	char		*result;
	char		*mod;

	if (!(mod = (*com)->modifier))
		return ;
	if (*mod == 'd' || *mod == 'D' || *mod == 'i')
	{
		if ((*com)->var.d < 0)
			return ;
		else if (ft_strchr_qt((*com)->flag, '+') > 0)
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
** # flag
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
		result = ft_strjoin("", (*com)->scroll);
	else
		result = ft_strjoin_and_free(beg, (*com)->scroll, 1, 0);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = ft_strlen(result);
}
