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

void			ft_nothing(void)
{
	return ;
}

void			ft_free_and_set(char **old, char **new)
{
	free(*old);
	*old = NULL;
	*old = *new;
}

char			*ft_add_spaces(char *str, char *width)
{
	long int	len;
	long int	spaces;
	char		*temp;
	long int	index;
	char		*result;
	long int	width_int;

	index = 0;
	len = ft_strlen(str);
	width_int = ft_atoi(width);
	if (width_int >= 0)
	{
		if (len >= width_int || len <= -(width_int))
			return (ft_strdup(str));
		spaces = width_int - len;
	}
	else
		spaces = -(width_int) - len;
	if (!(temp = ft_strnew((size_t)spaces + 1)))
		return (NULL);
	while (index < spaces)
		temp[index++] = ' ';
	if (width_int >= 0)
		result = ft_strjoin(temp, str);
	else
		result = ft_strjoin(str, temp);
	free(temp);
	return (result);
}
