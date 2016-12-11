/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:00 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/09 16:46:02 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_pre_print_width(t_com **com)
{
	char 			*result;

	if ((*com)->width)
	{
		result = ft_add_spaces((*com)->scroll, (*com)->width);
		free((*com)->scroll);
		(*com)->scroll = result;
		(*com)->len = ft_strlen(result);
	}
}
