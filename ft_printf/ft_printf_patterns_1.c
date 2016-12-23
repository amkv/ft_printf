/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_patterns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:05:45 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/08 15:05:47 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_pat_one(t_com **com, t_com **fresh, char **holder, size_t *yn)
{
	if (*yn == 0)
	{
		(*fresh)->scroll = *holder;
		(*fresh)->len = ft_strlen(*holder);
		ft_tcom_list(*&com, *fresh);
		return (1);
	}
	return (0);
}

char		*ft_pat_parameter(char **holder)
{
	char	*copy;
	char	*parameter;
	char	*new_holder;
	size_t	len;

	if (!(*holder))
		return (NULL);
	len = 0;
	copy = *holder;
	while (ft_isdigit(*copy) == 1)
	{
		len++;
		copy++;
	}
	if (len > 0 && *copy == '$')
	{
		parameter = ft_strnew(len + 1);
		ft_memcpy(parameter, *holder, len);
		new_holder = ft_strdel_begn(*holder, len + 1);
		ft_free_and_set(*&holder, &new_holder);
		return (parameter);
	}
	return (NULL);
}

static void	ft_pat_flags_parser(char **flag)
{
	char	*flag_copy;
	char	*result;
	char	*result_copy;
	char	*tab;

	flag_copy = *flag;
	result = ft_strnew(5 + 1);
	result_copy = result;
	tab = ft_strnew_char_filled(5, 0);
	while (*flag_copy)
	{
		if (*flag_copy == '-' && (tab[0]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '+' && (tab[1]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == ' ' && (tab[2]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '0' && (tab[3]++ < 1))
			*result_copy++ = *flag_copy;
		if (*flag_copy == '#' && (tab[4]++ < 1))
			*result_copy++ = *flag_copy;
		flag_copy++;
	}
	ft_free_and_set(*&flag, &result);
	free(tab);
}

char		*ft_pat_flags(char **holder)
{
	char	*new_holder;
	char	*flag;
	char	*copy;
	size_t	len;

	if (!(*holder) || ft_is_flag(**holder) == 0)
		return (NULL);
	flag = NULL;
	copy = *holder;
	len = 0;
	while (ft_is_flag(*copy) == 1)
	{
		copy++;
		len++;
	}
	flag = ft_strdupn(*holder, len);
	new_holder = ft_strdel_begn(*holder, len);
	ft_free_and_set(*&holder, &new_holder);
	if (flag != NULL)
		ft_pat_flags_parser(&flag);
	return (flag);
}

char		*ft_pat_width(char **holder)
{
	char	*new_holder;
	char	*width;
	char	*copy;

	if (!(*holder))
		return (0);
	copy = *holder;
	if (*copy == '*')
	{
		width = ft_strdup("*");
		new_holder = ft_strdel_begn(*holder, 1);
		ft_free_and_set(*&holder, &new_holder);
		return (width);
	}
	if (ft_isdigit(*copy) == 1)
	{
		width = ft_itoa(ft_atoi(*holder));
		new_holder = ft_strdel_begn(*holder, ft_strlen(width));
		ft_free_and_set(*&holder, &new_holder);
		return (width);
	}
	return (NULL);
}
