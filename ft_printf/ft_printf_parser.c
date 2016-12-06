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

/*
**		static void	ft_resizer()
**		{
**			if (len == 1)
**				комманда = первой букве
**			if (len == 2)
**				проверить обе буквы по правилу
**			if (len == 3)
**				проверить три буквы
**		}
**
**		static int ft_proverka(char c)
**		{
**			char *str;
**
**			str = "diufFeEgGxXoscpaAn";
**			while (*str)
**			{
**				if (*str == c)
**					return (1);
**			}
**			return (0);
**		}
*/

static void	ft_tcom_list(t_com **list, size_t counter, char *holder)
{
	char	sign;

	if (counter > 0)
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
		}
	if (*yn > 0)
		(*beg)++;
}

static void	ft_second_check(char **holder, size_t yn)
{
	char	*copy;
	size_t	len;

	if (yn == 0)
		return ;
	copy = *holder;
	len = ft_strlen(copy);
	if (len == 1)
		return ;
	if (len == 2)
		printf("s:%zu", len);
}

/*
**	while (*copy)
**	{
**		copy++;
**	}
*/

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
		ft_second_check(&holder, yn);
		ft_tcom_list(*&com, yn, holder);
		(*argc)++;
	}
}
