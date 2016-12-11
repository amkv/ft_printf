/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:54:40 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/08 14:54:41 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

long int			ft_numlen(long int num)
{
	long int		len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}
