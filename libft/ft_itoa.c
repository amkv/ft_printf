/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 10:05:18 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/03 10:07:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(result = (char*)malloc(sizeof(result) * 2)))
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		result[1] = '\0';
		result = ft_strjoin(result, ft_itoa(-n));
	}
	else if (n >= 10)
		result = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		result[0] = n + '0';
		result[1] = '\0';
	}
	return (result);
}
