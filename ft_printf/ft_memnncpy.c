/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:01:19 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/01 14:01:21 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		*ft_memnncpy(void *dst, const void *src, size_t start, size_t n)
{
	size_t	i;

	i = 0;
	while (i < start && *(unsigned char*)src != '\0')
	{
		src++;
		i++;
	}
	return (ft_memcpy(dst, src, n));
}
