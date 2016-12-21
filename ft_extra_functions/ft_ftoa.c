/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:00:31 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/10 11:00:32 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** не верный, необходимо переписать полностью
*/

char		*ft_ftoa(double number, int length)
{
	char	*result;
	char	*part1;
	char	*part2;
	int		i_left;
	double	f_right;

	if (length < 0 || length > 10)
		return (NULL);
	i_left = (int)number;
	f_right = number - (double)i_left;
	result = ft_itoa(i_left);
	part1 = ft_strjoin(result, ".");
	free(result);
	f_right = f_right * ft_pow(10, length);
	part2 = ft_itoa((int)f_right);
	result = ft_strjoin(part1, part2);
	free(part1);
	free(part2);
	return (result);
}
