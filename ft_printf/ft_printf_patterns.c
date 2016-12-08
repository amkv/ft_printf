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
	int 	len;

	copy = *holder;
	len = 0;
	while (ft_isdigit(*copy) == 1)
	{
		copy++;
		len++;
	}
	if (len > 0 && *copy == '$')
		return (NULL);
	return (NULL);
}

char		*ft_pat_width(char **holder)
{
	char 	*copy;
	char 	*result;
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
	*holder = ft_strdel_begn(*holder, len);
	return (result);
}

char 		*ft_pat_string(char **holder)
{
	return (*holder);
}
