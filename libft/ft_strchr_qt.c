/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_qt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:59:51 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/01 15:59:53 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strchr_qt(const char *s, char c)
{
	size_t	quantity;

	if (s)
	{
		quantity = 0;
		while (*s)
		{
			if (*s == c)
				quantity++;
			s++;
		}
		return (quantity);
	}
	else
		return (0);
}
