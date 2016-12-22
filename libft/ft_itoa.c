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

static void	ft_itoa_helper(char **result, long int n)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_itoa(n / 10);
	temp2 = ft_itoa(n % 10);
	*result = ft_strjoin(temp1, temp2);
	free(temp1);
	free(temp2);
}

char		*ft_itoa(long int n)
{
	char	*result;
	char	*temp;

	result = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		temp = ft_itoa(-n);
		result = ft_strjoin("-", temp);
		free(temp);
	}
	else if (n >= 10)
		ft_itoa_helper(&result, n);
	else if (n < 10 && n >= 0)
	{
		result = ft_strnew(2);
		if (!result)
			return (NULL);
		result[0] = (int)n + '0';
		result[1] = '\0';
	}
	return (result);
}
