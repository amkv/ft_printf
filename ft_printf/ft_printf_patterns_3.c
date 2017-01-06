/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:56:17 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 13:56:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_pat_precision_3(char **prec, char **new_holder, char **holder)
{
	*prec = ft_itoa(ft_atoi(*holder));
	*new_holder = ft_strdel_begn(*holder, ft_strlen(*prec));
	ft_free_and_set(*&holder, *&new_holder);
}

static void	ft_pat_precision_2(char **prec, char **new_holder, char **holder)
{
	*prec = ft_strdup("*");
	*new_holder = ft_strdel_begn(*holder, 1);
	ft_free_and_set(*&holder, *&new_holder);
}

static void	ft_pat_precision_1(char **prec, char **new_holder, char **holder)
{
	if (ft_isdigit(*(*holder + 1)) == 1)
		*prec = ft_itoa(ft_atoi(*holder + 1));
	else if (*(*holder + 1) == '*')
		*prec = ft_strdup("*");
	if (*prec == NULL || (*prec && **prec == '0'))
		*prec = ft_strdup("!");
	if (ft_isdigit(*(*holder + 1)) == 1)
		*new_holder = ft_strdel_begn(*holder, ft_strlen(*prec) + 1);
	else if (*(*holder + 1) == '*')
		*new_holder = ft_strdel_begn(*holder, 2);
	else
		*new_holder = ft_strdup(*holder + 1);
	ft_free_and_set(*&holder, *&new_holder);
}

char		*ft_pat_precision(char **holder)
{
	char	*new_holder;
	char	*precision;

	if (!(*holder))
		return (NULL);
	precision = NULL;
	if (**holder == '.')
		ft_pat_precision_1(&precision, &new_holder, *&holder);
	else if (**holder == '*')
		ft_pat_precision_2(&precision, &new_holder, *&holder);
	else if (ft_isdigit(**holder) == 1)
		ft_pat_precision_3(&precision, &new_holder, *&holder);
	return (precision);
}
