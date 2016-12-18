/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:22:19 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/15 13:22:21 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_flags_octo(t_com **com)
{
	ft_mod_add_0x(*&com);
	return ;
}

void		ft_flags_zero(t_com **com)
{
	return ;
}

void		ft_flags_minus(t_com **com)
{
	ft_mod_add_spaces(*&com);
	return ;
}

void		ft_flags_plus(t_com **com)
{
	ft_mod_add_sign(*&com);
	return ;
}

void		ft_flags_space(t_com **com)
{
	return ;
}
