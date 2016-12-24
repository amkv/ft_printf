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


	if (!(*com)->modifier || (*(*com)->scroll == '0'
			&& *(*com)->modifier != 'x' && *(*com)->modifier != 'X'))
		return (0);
	if (ft_strchr_qt((*com)->flag, '-') > 0 && ft_strchr_qt((*com)->flag, '0') > 0)
		return (0);
	c = *(*com)->modifier;
	if (c == 'd' || c == 'D' || c == 'x' || c == 'X' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'i' || c == 's')
	{
		if ((*com)->flag && ft_strchr_qt((*com)->flag, '0') > 0)
			return (1);
	}
	return (0);
}

char 			*ft_strjoin_and_free(char *str1, char *str2, int a, int b)
{
	char 		*result;

	if (!str1 || !str2)
		return (NULL);
	if (!(result = ft_strjoin(str1, str2)))
		return (NULL);
	if (a > 0)
	{
		free(str1);
		str1 = NULL;
	}
	if (b > 0)
	{
		free(str2);
		str2 = NULL;
	}
	return (result);
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
	else if ((*(*com)->scroll == '-' || *(*com)->scroll == '+') && *spaces == '0')
	{
		temp = ft_strdel_begn((*com)->scroll, 1);
		temp2 = ft_strjoin(spaces, temp);
		free(temp);
		if (*(*com)->scroll == '+')
			*result = ft_strjoin_and_free("+", temp2, 0, 1);
		if (*(*com)->scroll == '-')
			*result = ft_strjoin_and_free("-", temp2, 0, 1);
	}
	else
		*result = ft_strjoin(spaces, (*com)->scroll);
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
		|| *modifier == 'U' || *modifier == 'x' || *modifier == 'X'
		|| *modifier == 'p')
		return (1);
	return (0);
}

static void		ft_set_result(char **result, char **spaces, t_com **com)
{
	char		*temp;
	char 		*temp2;

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
		temp = ft_strdel_begn((*com)->scroll, 2);
		temp2 = ft_strjoin("0x", *spaces);
		*result = ft_strjoin_and_free(temp2, temp, 1, 1);
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
	{
		if (*(*com)->modifier == 'p')
		{
			if ((*com)->width && ((size_t)ft_atoi((*com)->precision)) > (*com)->len)
				spaces = ft_strnew_char_filled((size_t)ft_atoi((*com)->precision) - (*com)->len + 2, '0');
			else
				spaces = ft_strnew_char_filled(precision - 1, '0');
		}
		else
			spaces = ft_strnew_char_filled(precision - len, '0');
	}
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
