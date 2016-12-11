/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 18:13:25 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/29 18:13:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	while ((*s1 == *s2) && *s1 != '\0' && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	if (*s1 != *s2)
		return (0);
	return (1);
}