/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:03:00 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:03:01 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** zero flag
*/

static void		ft_mod_add_zero_1(t_com **com, size_t *width, char **result)
{
	char		*zeros;

	zeros = NULL;
	if (*width > (*com)->len)
		zeros = ft_strnew_char_filled(*width - (*com)->len, '0');
	else if (*width <= (*com)->len)
		zeros = ft_strdup("");
	if (*(*com)->modifier == 'p')
		*result = ft_strjoin((*com)->scroll, zeros);
	else
	{
		if (!(*com)->scroll)
			(*com)->scroll = ft_strnew(1);
		*result = ft_strjoin(zeros, (*com)->scroll);
	}
	ft_free_and_set(&(*com)->scroll, *&result);
	free(zeros);
}

void			ft_mod_add_zero(t_com **com)
{
	char		*mod;
	char		*result;
	size_t		width;

	if (!(mod = (*com)->modifier))
		return ;
	if ((*com)->precision || ((*mod == 'd' || *mod == 'D' || *mod == 'i'
		|| *mod == 'o' || *mod == 'O' || *mod == 'u' || *mod == 'U'
		|| *mod == 'x' || *mod == 'X')) || !(*com)->width)
		return ;
	width = (size_t)ft_atoi((*com)->width);
	ft_mod_add_zero_1(*&com, &width, &result);
	if (*mod == 'c')
		(*com)->len = width;
	else if (*mod == 'S')
		(*com)->len = width;
	else
		(*com)->len = ft_strlen((*com)->scroll);
	free((*com)->width);
	(*com)->width = NULL;
}
