/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:41:42 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/17 16:41:43 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*ft_strdupn(const char *s1, size_t n)
{
	char	*result;
	char	*temp;

	if (!s1)
		return (NULL);
	result = ft_strnew(n + 1);
	temp = result;
	if (result != NULL)
	{
		while (*s1 && n > 0)
		{
			*temp++ = *s1++;
			n--;
		}
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}
