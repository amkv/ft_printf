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

char 	*ft_pat_parameter(char **holder)
{
	char	*copy;
	size_t 	len;
	char 	*result;
	char 	*temp;

	copy = *holder;
	len = 0;
	while (ft_isdigit(*copy) == 1)
	{
		copy++;
		len++;
	}
	if (len > 0 && *copy == '$')
	{
		result = ft_strnew(len + 1);
		ft_memcpy(result, *holder, len);
		temp = ft_strdel_begn(*holder, len + 1);
//		free(*holder);
		*holder = NULL;
		*holder = temp;
		return (result);
	}
	return (NULL);
}

char		*ft_pat_width(char **holder)
{
	char 	*copy;
	char 	*result;
	char 	*temp;
	size_t 	len;

	copy = *holder;
	len = 0;
	while (ft_isdigit(*copy) && *copy && ft_is_modifier(*copy) == 0)
	{
		copy++;
		len++;
	}
	if (len == 0)
		return (NULL);
	else
	{
		result = ft_strnew(len + 1);
		ft_memcpy(result, *holder, len);
	}
	temp = ft_strdel_begn(*holder, len);
	free(*holder);
	*holder = NULL;
	*holder = temp;
	return (result);
}

char 		*ft_pat_string(char **holder)
{
	return (*holder);
}

char 		*ft_pat_modifier(char **holder)
{
	size_t 	len;
	char 	*copy;
	char 	*modifier;

	if (ft_is_modifier(**holder) == 0)
		return (0);
	len = ft_strlen(*holder);
	if (len == 1)
		return (*holder);
	copy = *holder;
	copy++;
	len--;
	modifier = ft_strnew(len + 1);
	ft_memcpy(modifier, copy, len);
	*holder = ft_strdel_begn(*holder, 1);
	return (modifier);
}
