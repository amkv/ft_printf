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

char 		*ft_add_spaces(char *str, size_t width)
{
	size_t	len;
	size_t 	spaces;
	char 	*temp;
	char 	*result;
	size_t 	index;

	len = ft_strlen(str);
	if (len >= width)
		return (ft_strdup(str));
	spaces = width - len;
	temp = ft_strnew(spaces + 1);
	if (!temp)
		return (NULL);
	index = 0;
	while (index < spaces)
		temp[index++] = ' ';
	result = ft_strjoin(temp, str);
	if (!result)
		return (NULL);
	free(temp);
	return (result);
}
