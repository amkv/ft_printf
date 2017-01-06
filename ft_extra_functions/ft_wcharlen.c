/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:08:08 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 13:08:09 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t		ft_wcharlen(wchar_t wchar)
{
	size_t	length;

	length = 0;
	if (wchar < (1 << 7))
		length = 1;
	else if (wchar < (1 << 11))
		length = 2;
	else if (wchar < (1 << 16))
		length = 3;
	else if (wchar < (1 << 21))
		length = 4;
	return (length);
}
