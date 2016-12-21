/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:01:43 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:01:44 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				ft_do_s(char *str, t_com **com)
{
	char			*result;

	if (str == NULL)
	{
		(*com)->scroll = ft_strdup("(null)");
		(*com)->len = 6;
		return ;
	}
	result = ft_strdup(str);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(str);
}

void				ft_do_ss(char *str, t_com **com)
{
	return ;
}
