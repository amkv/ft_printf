/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:07:23 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:07:24 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				ft_do_p(void *ptr, t_com **com)
{
	char			*str;
	char			*result;
	long int		pointer;

	pointer = (long int)*&ptr;
	str = ft_itoa_base(pointer, 16);
	result = ft_strjoin("0x", str);
	free(str);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}
