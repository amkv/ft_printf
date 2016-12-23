/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:01 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 20:03:34 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ****************************************************************************
*/

void			ft_free_and_set(char **old, char **new)
{
	free(*old);
	*old = NULL;
	*old = *new;
}

/*
** ****************************************************************************
*/

void			ft_putstrn(const char *str, size_t n)
{
	while (*str && n > 0)
	{
		ft_putchar(*str);
		n--;
	}
}

/*
** ****************************************************************************
*/

char			*ft_strnew_char_filled(size_t len, char c)
{
	char		*result;
	char		*temp;

	result = ft_strnew(len + 1);
	if (!result)
		return (NULL);
	temp = result;
	while (len-- > 0)
		*temp++ = c;
	*temp = '\0';
	return (result);
}

/*
** ****************************************************************************
*/

static int		ft_add_spaces_helper(t_com **com)
{
	char		c;

	if (!(*com)->modifier)
		return (0);
	c = *(*com)->modifier;
	if (c == 'd' || c == 'D' || c == 'x' || c == 'X' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'i')
	{
		if ((*com)->flag && *(*com)->flag == '0')
			return (1);
	}
	return (0);
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
	if ((*com)->flag && *(*com)->flag == '-')
	{
		result = ft_strjoin((*com)->scroll, spaces);
		free((*com)->width);
		(*com)->width = NULL;
	}
	else
		result = ft_strjoin(spaces, (*com)->scroll);
	free(spaces);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = width;
}

/*
** ****************************************************************************
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
	result = ft_strjoin(beg, (*com)->scroll);
	free(beg);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

/*
** ***** for big X *************************************************************
*/

void			ft_mod_string_to_upper(char *str, t_com **com)
{
	char		*temp;
	char		*result;
	char		*copy;

	temp = str;
	result = ft_strnew(ft_strlen(str) + 1);
	if (result == NULL)
		return ;
	copy = result;
	while (*temp)
	{
		*copy = (char)ft_toupper(*temp);
		copy++;
		temp++;
	}
	*copy = '\0';
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

/*
** ******************  PRECISION  *********************************************
*/

void			ft_mod_cut_word(t_com **com, size_t precision)
{
	char		*result;

	if (!(*com)->scroll || !(*com)->modifier)
		return ;
	if (*(*com)->modifier == 'x' || *(*com)->modifier == 'X'
		|| *(*com)->modifier == 'd' || *(*com)->modifier == 'i')
		return ;
	result = ft_strdupn((*com)->scroll, precision);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = precision;
	return ;
}

/*
** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** *** ***
*/

static int		ft_check_modifier(char *modifier)
{
	if (!modifier)
		return (-1);
	if (*modifier == 'd' || *modifier == 'D' || *modifier == 'i' ||
		*modifier == 'o' || *modifier == 'O' || *modifier == 'u'
		|| *modifier == 'U' || *modifier == 'x' || *modifier == 'X')
		return (1);
	return (0);
}

static void		ft_set_result(char **result, char **spaces, t_com **com)
{
	char		*temp;

	if ((*com)->var.d < 0)
	{
		*result = ft_itoa(-((*com)->var.d));
		temp = ft_strjoin(*spaces, *result);
		free(*result);
		*result = ft_strjoin("-0", temp);
		free(temp);
	}
	else
		*result = ft_strjoin(*spaces, (*com)->scroll);
}

void			ft_mod_extend_word(t_com **com, size_t precision, size_t len)
{
	char		*result;
	char		*spaces;

	if (ft_check_modifier((*com)->modifier) == -1)
		return ;
	else if (ft_check_modifier((*com)->modifier) == 1)
		spaces = ft_strnew_char_filled(precision - len, '0');
	else
		spaces = ft_strnew_char_filled(precision - len, ' ');
	if (*(*com)->modifier == 'd' || *(*com)->modifier == 'i')
		ft_set_result(&result, &spaces, *&com);
	else
		result = ft_strjoin(spaces, (*com)->scroll);
	free(spaces);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = ft_strlen((*com)->scroll);
}

/*
** ******* minus flag *********************************************************
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
	size_t 		width;

	mod = (*com)->modifier;
	if ((*com)->precision || (mod && (*mod == 'd' || *mod == 'D' || *mod == 'i'
		|| *mod == 'o' || *mod == 'O' || *mod == 'u' || *mod == 'U'
		|| *mod == 'x' || *mod == 'X')) || !(*com)->width)
		return ;
	width = (size_t)ft_atoi((*com)->width);
	zeros = NULL;
	if (width > (*com)->len)
		zeros = ft_strnew_char_filled(width - (*com)->len, '0');
	if (width <= (*com)->len)
		zeros = ft_strdup("");
	result = ft_strjoin(zeros, (*com)->scroll);
	ft_free_and_set(&(*com)->scroll, &result);
	free(zeros);
	if (*mod == 'c')
		(*com)->len = width;
	else
		(*com)->len = ft_strlen((*com)->scroll);
	free((*com)->width);
	(*com)->width = NULL;
}

/*
** ****** 1 space flag *******************************************************
*/

int 			ft_is_flag_exist(const char *flags)
{
	while (*flags)
	{

	}
	return (0);
}


void 			ft_mod_add_one_space(t_com **com)
{
	char 		*result;

	result = ft_strjoin(" ", (*com)->scroll);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len += 1;
}
