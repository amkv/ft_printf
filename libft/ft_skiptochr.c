/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skiptochr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:33:43 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/03 20:34:12 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skiptochr(char *s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s - 1);
			s++;
		}
		return (s - 1);
	}
	else
		return (NULL);
}