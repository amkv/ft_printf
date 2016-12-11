/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspace_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:46:52 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/30 16:46:54 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_skipspace_end(char *s)
{
	unsigned int	len;

	if (s)
	{
		len = ft_strlen(s);
		if (len == 0)
			return (s);
		s = s + (len - 1);
		while ((*s == ' ' || *s == '\n' || *s == '\t') && len-- > 0)
			s--;
		return (s);
	}
	else
		return (NULL);
}
