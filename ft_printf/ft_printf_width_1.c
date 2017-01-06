/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:40:07 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/04 19:40:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ******* pre print width *******************************************
*/

void			ft_pre_print_width(t_com **com)
{
	intmax_t	width;
	size_t		len;
	size_t		new_width;
	char 		*spaces;
	char 		*result;

	if ((*com)->width)
	{
		width = ft_atoi((*com)->width);
		if (width < 0)
		{
			new_width = (size_t)-width;
			len = (*com)->len;
			spaces = ft_strnew_char_filled(new_width - len, ' ');
			result = ft_strjoin((*com)->scroll, spaces);
			free((*com)->scroll);
			free(spaces);
			(*com)->scroll = result;
			if (new_width > len)
				(*com)->len = (size_t)new_width;
		}
//		else if ((*com)->precision && ft_atoi((*com)->precision) == 0
//				 && width <= 0)
//			return ;
//		else if ((*com)->modifier && *(*com)->modifier == 'p')
//		{
//			;
//		}
		else
			ft_mod_add_spaces(*&com);
	}
}

/*
** ************ width *********************************************
*/

static int		ft_add_spaces_helper(t_com **com)
{
	char 		*flag;

	if (!(flag = (*com)->flag))
		return (0);
	if (ft_strchr_qt(flag, '-') > 0 && ft_strchr_qt(flag, '0') > 0)
		return (0);
	if (ft_strchr_qt(flag, '0') > 0 && ft_atoi((*com)->precision) == 0)
		return (1);
	return (0);
}

static	void	ft_add_spaces_helper2(char **result, char *spaces, t_com **com)
{
	char 		*temp;
	char 		*temp2;

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
	else if ((*com)->scroll &&
			 ((*(*com)->scroll == '-' || *(*com)->scroll == '+')) && *spaces == '0')
	{
		temp = ft_strdel_begn((*com)->scroll, 1);
		temp2 = ft_strjoin(spaces, temp);
		free(temp);
		if (*(*com)->scroll == '+')
			*result = ft_strjoin_and_free("+", temp2, 0, 1);
		if (*(*com)->scroll == '-')
			*result = ft_strjoin_and_free("-", temp2, 0, 1);
	}
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
	size_t		len;

	if (!(*com)->width)
		return ;
	width = (size_t)ft_atoi((*com)->width);
	if ((len = (*com)->len) >= width)
		return ;
	if (ft_add_spaces_helper(*&com) == 1)
		spaces = ft_strnew_char_filled(width - len, '0');
	else
		spaces = ft_strnew_char_filled(width - len, ' ');
	if ((*com)->flag && ft_strchr_qt((*com)->flag, '-') > 0)
	{
		if (!(*com)->scroll)
			result = ft_strjoin(ft_strnew(1), spaces); // LEAKS?
		else
			result = ft_strjoin((*com)->scroll, spaces);
		free((*com)->width);
		(*com)->width = NULL;
	}
	else
		ft_add_spaces_helper2(&result, spaces, *&com);
	free(spaces);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = width;
}
