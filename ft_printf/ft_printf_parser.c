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

static void	ft_checker(char **str, size_t *yn, size_t *len, size_t *beg)
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

size_t		ft_parser(const char *format, t_com **list)
{
	size_t	tab[4];
	char	*copy;
	char	*holder;

	tab[0] = 0;
	tab[1] = 0;
	copy = (char*)format;
	while (*copy != '\0')
	{
		ft_checker(&copy, &tab[2], &tab[3], &tab[1]);
		if (*copy == '\0' && tab[3] == 0)
			return (tab[0]);
		ft_memnncpy((holder = ft_strnew(tab[3] + 1)), format, tab[1], tab[3]);
		tab[1] += tab[3];
		ft_tcom_list(*&list, tab[2], holder);
		tab[0]++;
	}
	ft_tcom_revert(*&list);
	return (tab[0]);
}
