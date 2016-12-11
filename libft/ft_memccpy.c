/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:23:46 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/28 10:23:49 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstptr;
	const unsigned char	*srcptr;

	srcptr = src;
	dstptr = dst;
	while (n > 0)
	{
		*dstptr = *srcptr;
		if (*srcptr == (unsigned char)c)
			return (++dstptr);
		n--;
		dstptr++;
		srcptr++;
	}
	return (NULL);
}
