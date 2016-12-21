/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_d_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:09:50 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:09:51 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_do_d(int d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_h(short d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_hh(signed char d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_l(long d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}

void	ft_do_d_ll(long long d, t_com **com)
{
	(*com)->scroll = ft_itoa_base(d, 10);
}
