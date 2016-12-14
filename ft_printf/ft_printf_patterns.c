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

/*
int	ft_pat_one(t_com **com, char **holder)
{
	if (ft_strlen(*holder) == 1 && ft_is_modifier(**holder) == 1)
	{
		(*com)->modifier = ft_strdup(*holder);
//		free((*com)->scroll);
//		(*com)->scroll = NULL;
//		(*com)->len = 0;
		return (1);
	}
	return (0);
}
*/

/*
int	ft_pat_one(t_com **com)
{
	char 	*holder;

	holder = (*com)->scroll;
	if (ft_strlen(holder) == 1 && ft_is_modifier(*holder) == 1)
	{
		(*com)->modifier = ft_strdup(holder);
		free((*com)->scroll);
		(*com)->scroll = NULL;
		(*com)->len = 0;
		return (1);
	}
	return (0);
}
*/

char			*ft_pat_string(char **holder)
{
	return (*holder);
}

char			*ft_pat_parameter(char **holder)
{
	char		*copy;
	char		*parameter;
	char		*new_holder;
	size_t		len;

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

char			*ft_pat_flags(char **holder)
{
	char		*new_holder;
	char		*flag;

	if (!(*holder) || ft_is_flag(**holder) == 0)
		return (NULL);
	flag = ft_strnew(2);
	flag = ft_memcpy(flag, *holder, 1);
	new_holder = ft_strdel_begn(*holder, 1);
	ft_free_and_set(*&holder, &new_holder);
	return (flag);
}

long int		ft_pat_width(char **holder)
{
	char		*new_holder;
	long int	width;
	size_t		len;

	if (!(*holder))
		return (0);
	width = ft_atoi(*holder);
	len = (size_t)ft_numlen(width);
	if (len == 0)
		return (0);
	new_holder = ft_strdel_begn(*holder, len);
	ft_free_and_set(*&holder, &new_holder);
	return (width);
}

char			*ft_pat_precision(char **holder)
{
	char		*new_holder;
	char		*precision;

	if (!(*holder))
		return (NULL);
	precision = *holder;
	if (**holder == '.')
	{
		new_holder = *holder;
		if (*(new_holder + 1) != '\0')
			new_holder++;
		precision = ft_itoa(ft_atoi(new_holder));
		new_holder = ft_strdel_begn(*holder, ft_strlen(precision) + 1);
	}
	else if (**holder == '*')
	{
		precision = ft_strdup("*");
		new_holder = ft_strdel_begn(*holder, 1);
	}
	else
		return (NULL);
	ft_free_and_set(*&holder, &new_holder);
	return (precision);
}

char			*ft_pat_modifier(char **holder)
{
	char		*modifier;
	char		*new_holder;

	if (!(*holder) || ft_is_modifier(**holder) == 0)
		return (NULL);
	if (ft_strlen(*holder) == 1)
	{
		modifier = ft_strdup(*holder);
		free(*holder);
		*holder = NULL;
		return (modifier);
	}
	modifier = ft_strnew(2);
	ft_memcpy(modifier, *holder, 1);
	new_holder = ft_strdel_begn(*holder, 1);
	ft_free_and_set(*&holder, &new_holder);
	return (modifier);
}
