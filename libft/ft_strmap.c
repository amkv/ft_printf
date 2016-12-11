/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:51:03 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/29 17:51:04 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr;

	if (s)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str)
		{
			ptr = str;
			while (*s)
				*ptr++ = f(*s++);
			*ptr = '\0';
			return (str);
		}
	}
	return (NULL);
}
