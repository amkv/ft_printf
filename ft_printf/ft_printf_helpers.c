/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:01 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 20:03:34 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_nothing(void)
{
	return ;
}

char 		*ft_add_spaces(char *str, size_t space)
{
	char 	*result;
	char 	*copy;
	size_t 	index;

	index = 0;
	result = ft_strnew(space + 1);
	if (!result)
		return (NULL);
	copy = result;
	while (index < space)
	{
		*copy++ = ' ';
		index++;
	}
	copy = ft_strjoin(result, str);
	free(result);
	return (copy);
}
