/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:39:01 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/10 11:39:02 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

double			ft_pow(double x, double y)
{
	double		result;

	result = 1;
	while (y != 0)
	{
		result = result * x;
		y--;
	}
	return (result);
}
