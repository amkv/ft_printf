/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:09:41 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/06 15:09:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static long int	ft_return_value(long int v)
{
	if (v < 0)
		return (-(v));
	else
		return (v);
}

static void	ft_aux(long int value, long int base, char *result, int *index)
{
	char	b[17];
	int		i;

	i = -1;
	while (i++ < 10)
		b[i] = (char)(i + '0');
	b[10] = 'a';
	b[11] = 'b';
	b[12] = 'c';
	b[13] = 'd';
	b[14] = 'e';
	b[15] = 'f';
	b[16] = '\n';
	if (value <= -base || base <= value)
		ft_aux((value / base), base, result, index);
	result[(*index)++] = (char)b[ft_return_value(value % base)];
}

char		*ft_itoa_base(long int value, long int base)
{
	char	*result;
	int		index;

	if (base < 2 || base > 16 || !(result = ft_strnew(35)))
		return (NULL);
	index = 0;
	if (base == 10 && value < 0)
		result[index++] = '-';
	ft_aux(value, base, result, &index);
	result[index] = '\0';
	return (result);
}
