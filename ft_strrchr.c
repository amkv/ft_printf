/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:44:53 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/24 15:44:55 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*match;
	int		truth;

	truth = 0;
	while (*s != '\0')
	{
		if (c == *s)
		{
			match = (char*)s;
			truth = 1;
		}
		s++;
	}
	if (truth > 0)
		return (match);
	if (c == '\0')
		return ((char*)s);
	else
		return (NULL);
}
