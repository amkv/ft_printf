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

char 			*ft_add_spaces(char *str, long int width)
{
	long int	len;
	long int	spaces;
	char 		*temp;
	long int	index;
	char 		*result;

	index = 0;
	len = ft_strlen(str);
	if (width >= 0)
	{
		if (len >= width || len <= -(width))
			return (ft_strdup(str));
		spaces = width - len;
	}
	else
		spaces = -(width) - len;
	if (!(temp = ft_strnew((size_t)spaces + 1)))
		return (NULL);
	while (index < spaces)
		temp[index++] = ' ';
	if (width >= 0)
		result = ft_strjoin(temp, str);
	else
		result = ft_strjoin(str, temp);
	free(temp);
	return (result);
}



