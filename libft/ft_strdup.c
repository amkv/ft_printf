/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:46:40 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/23 19:46:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	char	*temp;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	result = (char*)malloc(sizeof(char) * (len + 1));
	temp = result;
	if (result != NULL)
	{
		while (*s1)
			*temp++ = *s1++;
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}
