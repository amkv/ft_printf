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

long int	ft_pat_width(char **holder)
{
//	char 	*result;
	char 	*temp;
	size_t 	len;
	long int num;

	num = ft_atoi(*holder);
	len = (size_t)ft_numlen(num);
//	if (len == 0)
//		return (0);
	temp = ft_strdel_begn(*holder, len);
	free(*holder);
	*holder = NULL;
	*holder = temp;
	return (num);
}

//char		*ft_pat_width(char **holder)
//{
//	char 	*copy;
//	char 	*result;
//	char 	*temp;
//	size_t 	len;
//
//	copy = *holder;
//	len = 0;
//	while (ft_isdigit(*copy) && *copy && ft_is_modifier(*copy) == 0)
//	{
//		copy++;
//		len++;
//	}
//	if (len == 0)
//		return (NULL);
//	else
//	{
//		result = ft_strnew(len + 1);
//		ft_memcpy(result, *holder, len);
//	}
//	temp = ft_strdel_begn(*holder, len);
//	free(*holder);
//	*holder = NULL;
//	*holder = temp;
//	return (result);
//}

char 		*ft_pat_string(char **holder)
{
	return (*holder);
}

char 		*ft_pat_modifier(char **holder)
{
	size_t 	len;
	char 	*modifier;
	char 	*temp;

	if (!(*holder) || ft_is_modifier(**holder) == 0)
		return (NULL);
	len = ft_strlen(*holder);
	if (len == 1)
	{
		modifier = ft_strdup(*holder);
		free(*holder);
		*holder = NULL;
		return (modifier);
	}
	modifier = ft_strnew(2);
	ft_memcpy(modifier, *holder, 1);
	temp = ft_strdel_begn(*holder, 1);
	free(*holder);
	*holder = NULL;
	*holder = temp;
	return (modifier);
}
