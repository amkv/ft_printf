/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:32:04 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/04 19:32:06 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ******* pre print precision *******************************************
*/

void			ft_pre_print_precision(t_com **com)
{
	size_t		pre_ion;
	size_t		len;
	char		*mod;

	if (!(*com)->precision || !(mod = (*com)->modifier))
		return ;
	if ((*com)->var.c != 0 && (*mod == 'c' || *mod == 'C'))
	{
		free((*com)->scroll);
		(*com)->scroll = ft_strdup("*");
		*mod = 's';
		return ;
	}
	pre_ion = (size_t)ft_atoi((*com)->precision);
	len = (*com)->len;
	if ((pre_ion == 0 || (*mod == 's' && *mod == 'S')) || ((*com)->scroll
														   && *(*com)->scroll == '\0') || (*mod == 'p' && pre_ion < len) ||
		((*mod == 'u' || *mod == 'U') && pre_ion < len) || (*mod == 's'
															&& pre_ion >= len) || ((*mod == 'o' || *mod == 'O') && pre_ion < len))
		return ;
	else if (pre_ion < len)
		ft_mod_cut_word(*&com, pre_ion);
	else if (pre_ion > len)
		ft_mod_extend_word(*&com, pre_ion, len);
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

/*
** ***** cut *********  PRECISION  ****************************************
*/

static unsigned char	*ft_strdupn_wchar(const unsigned char *s1, size_t n)
{
	unsigned char	*result;
	unsigned char	*temp;

	if (!s1)
		return (NULL);
	result = (unsigned char*)malloc(sizeof(unsigned char) * n + 1);
	temp = result;
	if (result != NULL)
	{
		while (*s1 && n > 0)
		{
			*temp++ = *s1++;
			n--;
		}
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}

static void		ft_mod_cut_wchar_word(t_com **com, size_t precision)
{
	unsigned char	*result;
	wchar_t			*copy;
	size_t 			len;
	size_t 			temp;

	copy = (*com)->var.ws;
	len = 0;
	while (*copy)
	{
		if (len < precision)
		{
			temp = ft_wcharlen(*copy);
			if ((temp + len) > precision)
				break ;
			len += temp;
			copy++;
		}
		else
			break ;
	}
	result = ft_strdupn_wchar((*com)->w_scroll, len);
	free((*com)->w_scroll);
	(*com)->w_scroll = NULL;
	(*com)->w_scroll = result;
	(*com)->len = len;
}

void			ft_mod_cut_word(t_com **com, size_t precision)
{
	char		*result;

	if ((*com)->modifier && *(*com)->modifier == 'S')
	{
		ft_mod_cut_wchar_word(*&com, precision);
		return ;
	}
	if (!(*com)->scroll || !(*com)->modifier)
		return ;
	if (*(*com)->modifier == 'x' || *(*com)->modifier == 'X'
		|| *(*com)->modifier == 'd' || *(*com)->modifier == 'i')
		return ;
	result = ft_strdupn((*com)->scroll, precision);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = precision;
}

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