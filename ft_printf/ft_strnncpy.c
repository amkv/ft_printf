/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:27:06 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/01 11:27:07 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strnncpy(char *dst, const char *src, size_t start, size_t len)
{
	size_t 	i;

	i = 0;
	while (i < start && *src != '\0')
	{
		src++;
		i++;
	}
	return (ft_strncpy(dst, src, len));
}
