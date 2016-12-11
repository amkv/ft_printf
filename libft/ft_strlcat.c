/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:24:42 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/24 12:24:44 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	length;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		length = size + srclen;
	else
		length = dstlen + srclen;
	dst = dst + dstlen;
	dstlen += 1;
	while (dstlen < size && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		dstlen++;
	}
	*dst = '\0';
	return (length);
}
