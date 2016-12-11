/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:20:58 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/03 20:20:59 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_skipchr(char *s, char c)
{
	if (s)
	{
		while (*(unsigned char*)s == (unsigned char)c)
			s++;
		return ((char*)s);
	}
	else
		return (NULL);
}
