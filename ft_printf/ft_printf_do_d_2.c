/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_d_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:13:22 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:13:23 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void				ft_do_d_j(intmax_t d, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(d, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

//void				ft_do_d_t(size_t d, t_com **com)
//{
//	free((*com)->scroll);
//	(*com)->scroll = ft_itoa_base(d, 10);
//	(*com)->len = ft_strlen((*com)->scroll);
//}

void				ft_do_d_z(size_t d, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(d, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}

void				ft_do_dd(long int d, t_com **com) // не готова
{
	ft_do_d_l(d, *&com);
}

void				ft_do_i(int i, t_com **com) // OK
{
	free((*com)->scroll);
	(*com)->scroll = ft_itoa_base(i, 10);
	(*com)->len = ft_strlen((*com)->scroll);
}
