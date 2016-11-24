/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:42:12 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/28 10:42:14 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*dstptr;

	dstptr = dst;
	if (dst > src)
		while (len > 0)
		{
			len--;
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
		}
	else if (dst < src)
		while (len > 0)
		{
			len--;
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst++;
			src++;
		}
	return (dstptr);
}
