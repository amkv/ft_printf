/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:32:29 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:32:30 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** width
*/

static int		ft_add_spaces_helper_1(t_com **com)
{
	char		*flag;

	if (!(flag = (*com)->flag))
		return (0);
	if (ft_strchr_qt(flag, '-') > 0 && ft_strchr_qt(flag, '0') > 0)
		return (0);
	if (ft_strchr_qt(flag, '0') > 0 && ft_atoi((*com)->precision) == 0)
		return (1);
	if ((*com)->modifier && *(*com)->modifier == 'd' && (*com)->prec_flag > 0)
		return (1);
	return (0);
}

static void		ft_add_spaces_helper_3(char **result, char *spaces, t_com **com)
{
	char		*temp;
	char		*temp2;

	temp = ft_strdel_begn((*com)->scroll, 1);
	temp2 = ft_strjoin(spaces, temp);
	free(temp);
	if (*(*com)->scroll == '+')
		*result = ft_strjoin_and_free("+", temp2, 0, 1);
	if (*(*com)->scroll == '-')
		*result = ft_strjoin_and_free("-", temp2, 0, 1);
}

static void		ft_add_spaces_helper_2(char **result, char *spaces, t_com **com)
{
	char		*temp;
	char		*temp2;

	if (*spaces == '0' && ft_strchr_qt((*com)->flag, '0') > 0
		&& ft_strchr_qt((*com)->flag, '#') > 0
		&& (*(*com)->modifier == 'x' || *(*com)->modifier == 'X'))
	{
		temp = ft_strdupn((*com)->scroll, 2);
		temp2 = ft_strjoin(temp, spaces);
		free(temp);
		temp = ft_strdel_begn((*com)->scroll, 2);
		*result = ft_strjoin_and_free(temp2, temp, 1, 1);
	}
	else if ((*com)->scroll && ((*(*com)->scroll == '-'
			|| *(*com)->scroll == '+')) && *spaces == '0')
		ft_add_spaces_helper_3(*&result, *&spaces, *&com);
	else if (ft_strchr_qt((*com)->flag, ' ') > 0
			&& ft_strchr_qt((*com)->flag, '0') > 0)
		*result = ft_strjoin((*com)->scroll, spaces);
	else
	{
		if (!(*com)->scroll)
			(*com)->scroll = ft_strnew(1);
		*result = ft_strjoin(spaces, (*com)->scroll);
	}
}

void			ft_mod_add_spaces(t_com **com)
{
	char		*result;
	char		*spaces;
	size_t		width;

	if (!(*com)->width
		|| (*com)->len >= (width = (size_t)ft_atoi((*com)->width)))
		return ;
	if (ft_add_spaces_helper_1(*&com) == 1)
		spaces = ft_strnew_char_filled(width - (*com)->len, '0');
	else
		spaces = ft_strnew_char_filled(width - (*com)->len, ' ');
	if ((*com)->flag && ft_strchr_qt((*com)->flag, '-') > 0)
	{
		if (!(*com)->scroll)
			result = ft_strjoin(ft_strnew(1), spaces);
		else
			result = ft_strjoin((*com)->scroll, spaces);
		free((*com)->width);
		(*com)->width = NULL;
	}
	else
		ft_add_spaces_helper_2(&result, spaces, *&com);
	free(spaces);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = width;
}
