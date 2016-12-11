/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:13:26 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/30 16:13:27 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*copy;
	char			*beg;
	char			*end;

	if (s)
	{
		beg = ft_skipspace_beg((char*)s);
		end = ft_skipspace_end((char*)beg);
		if (!(copy = (char*)malloc(sizeof(char) * (ft_ptrlen(beg, end) + 1))))
			return (NULL);
		ft_strncpy(copy, beg, ft_ptrlen(beg, end));
		copy[ft_ptrlen(beg, end)] = '\0';
		return (copy);
	}
	else
		return (NULL);
}
