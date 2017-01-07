/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:53:10 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:53:11 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** *** *** extend *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
*/

static int		ft_check_modifier(char *modifier)
{
	if (!modifier)
		return (-1);
	if (*modifier == 'd' || *modifier == 'D' || *modifier == 'i' ||
		*modifier == 'o' || *modifier == 'O' || *modifier == 'u'
		|| *modifier == 'U' || *modifier == 'x' || *modifier == 'X'
		|| *modifier == 'p')
		return (1);
	return (0);
}

static void		ft_set_result(char **result, char **spaces, t_com **com)
{
	char		*temp;
	char		*temp2;

	if ((*(*com)->modifier == 'd' || *(*com)->modifier == 'i')
		&& (*com)->var.d < 0)
	{
		*result = ft_itoa(-((*com)->var.d));
		temp = ft_strjoin(*spaces, *result);
		free(*result);
		*result = ft_strjoin("-0", temp);
		free(temp);
	}
	else if (*(*com)->modifier == 'p')
	{
		if ((*com)->prec_flag == 1)
			*result = ft_strjoin(*spaces, (*com)->scroll);
		else
		{
			temp = ft_strdel_begn((*com)->scroll, 2);
			temp2 = ft_strjoin("0x", *spaces);
			*result = ft_strjoin_and_free(temp2, temp, 1, 1);
		}
	}
	else
		*result = ft_strjoin(*spaces, (*com)->scroll);
}

static void		ft_mod_processing(t_com **com, char **spaces,
									size_t precision, size_t len)
{
	if (*(*com)->modifier == 'p')
	{
		if ((*com)->prec_flag == 1)
			*spaces = ft_strnew_char_filled(
			(size_t)ft_atoi((*com)->precision)
			- ft_strlen((*com)->scroll), ' ');
		else if ((*com)->width
				&& ((size_t)ft_atoi((*com)->precision)) > (*com)->len)
			*spaces = ft_strnew_char_filled(
					(size_t)ft_atoi((*com)->precision) - (*com)->len + 2, '0');
		else
			*spaces = ft_strnew_char_filled(precision - 1, '0');
	}
	else if ((*com)->width_flag > 0 && (*com)->width_flag < 0)
		*spaces = ft_strnew_char_filled(precision - len, ' ');
	else
		*spaces = ft_strnew_char_filled(precision - len, '0');
}

void			ft_mod_extend_word(t_com **com, size_t precision, size_t len)
{
	char		*result;
	char		*spaces;

	if (ft_check_modifier((*com)->modifier) == -1)
		return ;
	else if (ft_check_modifier((*com)->modifier) == 1)
		ft_mod_processing(*&com, &spaces, precision, len);
	else
		spaces = ft_strnew_char_filled(precision - len, ' ');
	if (*(*com)->modifier == 'd' || *(*com)->modifier == 'i'
		|| *(*com)->modifier == 'p')
		ft_set_result(&result, &spaces, *&com);
	else
		result = ft_strjoin(spaces, (*com)->scroll);
	free(spaces);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = ft_strlen((*com)->scroll);
}
