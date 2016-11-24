/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:39:01 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/28 13:39:03 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *s1ptr;
	const unsigned char *s2ptr;

	s1ptr = s1;
	s2ptr = s2;
	if (n == 0)
		return (0);
	while (n > 1 && *s1ptr == *s2ptr)
	{
		s1ptr++;
		s2ptr++;
		n--;
	}
	return (*s1ptr - *s2ptr);
}
