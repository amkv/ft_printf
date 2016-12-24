/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uintmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 17:29:07 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 17:29:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_a(uintmax_t value, uintmax_t base, char *ret, int *i)
{
	char	*b;

	if (value == 0)
		return ;
	if (value <= -base || base <= value)
		ft_a((value / base), base, ret, i);
	b = ft_strdup("0123456789abcdef");
	ret[(*i)++] = b[value % base];
	free(b);
}

char		*ft_itoa_base_uintmax(uintmax_t value, uintmax_t base)
{
	char	*ret;
	int		index;

	if (value == 0)
		return (ft_strdup("0"));
	if (base < 2 || base > 16 || !(ret = ft_strnew(35)))
		return (NULL);
	index = 0;
	ft_a(value, base, ret, &index);
	ret[index] = '\0';
	return (ret);
}
