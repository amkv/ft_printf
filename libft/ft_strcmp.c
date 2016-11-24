/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:20:25 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/23 15:20:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *s1ptr;
	const unsigned char *s2ptr;

	s1ptr = (unsigned char*)s1;
	s2ptr = (unsigned char*)s2;
	while (*s1ptr != '\0' || *s2ptr != '\0')
	{
		if (*s1ptr == *s2ptr)
		{
			s1ptr++;
			s2ptr++;
		}
		else
			return (*s1ptr - *s2ptr);
	}
	return (0);
}
