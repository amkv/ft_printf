/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 19:48:40 by akalmyko          #+#    #+#             */
/*   Updated: 2016/09/30 19:48:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ptrlen(char *beg, char *end)
{
	size_t		len;

	if (beg && end)
	{
		len = 0;
		while (beg++ != end)
			len++;
		return (len + 1);
	}
	else
		return (1);
}
