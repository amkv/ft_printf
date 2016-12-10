/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:32 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/30 12:01:37 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int 	ft_check_modifier(const char *str)
{
	int 	len;

	len = 0;
	while (*str)
	{
		if (ft_is_modifier(*str) == 1)
			len++;
		str++;
	}
	if (len > 0)
		return (1);
	return (0);
}

static void	ft_tcom_list(t_com **list, size_t yn, char *holder)
{
	char	sign;

	if (yn > 0 && (ft_check_modifier(holder) == 1))
		sign = '%';
	else
		sign = '.';
	if (*list == NULL)
		*list = ft_tcom_new(sign, holder);
	else
		ft_tcom_add(*&list, ft_tcom_new(sign, holder));
}

static void	ft_get_arg(char **str, size_t *beg, size_t *yn, size_t *len)
{
	*yn = 0;
	*len = 0;
	if (**str == '%')
	{
		(*yn)++;
		(*str)++;
	}
	if (**str == '%')
		(*len) = 1;
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '%' && *(*str + 1) == '\0')
				(*len)++;
		}
	if (*yn > 0)
		(*beg)++;
}

void	ft_check_patterns(t_com **com, size_t *yn)
{
	char 	*holder;

	holder = (*com)->scroll;
	if (*yn == 0)
		return ;
	if (ft_strlen(holder) == 1 && ft_is_modifier(*holder) == 1)
	{
		(*com)->modifier = ft_strdup(holder);
		free((*com)->scroll);
		(*com)->scroll = NULL;
		return ;
	}
	(*com)->param = ft_pat_parameter(&holder);
//	(*com)->flag = ft_is_flags(&holder);
	(*com)->width = ft_pat_width(&holder);
//	(*com)->precision = ft_is_precision(&holder);
//	(*com)->length =  ft_is_lenght(&holder);
	(*com)->modifier = ft_pat_modifier(&holder);
	if (holder && *holder == '%' && ft_strlen(holder) == 1)
	{
		if ((*com)->width)
			(*com)->scroll = ft_add_spaces(holder, (*com)->width);
		else
			(*com)->scroll = holder;
		(*com)->len = ft_strlen((*com)->scroll);
		return ;
	}
	if (holder && ft_strlen(holder) > 0)
		ft_tcom_list(*&com, 0, holder);
	else
	{
		(*com)->scroll = NULL;
		(*com)->len = 0;
	}
//	(*com)->scroll = NULL;
}

void		ft_parser(const char *format, t_com **com, size_t *argc)
{
	char	*copy;
	char	*holder;
	size_t	beg;
	size_t	yn;
	size_t	len;

	*argc = 0;
	*com = NULL;
	beg = 0;
	copy = (char*)format;
	while (*copy != '\0')
	{
		ft_get_arg(&copy, &beg, &yn, &len);
		if (*copy == '\0' && len == 0)
			return ;
		ft_memnncpy((holder = ft_strnew(len + 1)), format, beg, len);
		beg += len;
		ft_tcom_list(*&com, yn, holder);
		ft_check_patterns(*&com, &yn);
		(*argc)++;
	}
}
