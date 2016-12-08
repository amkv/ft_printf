/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_begn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:56:36 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/08 14:56:38 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char 				*ft_strdel_begn(char *str, size_t n)
{
	char 			*result;
	size_t 			len;

	len = ft_strlen(str);
	result = ft_strnew(len - n + 1);
	ft_memnncpy(result, str, n, (len - n));
	free(str);
	return (result);
}
