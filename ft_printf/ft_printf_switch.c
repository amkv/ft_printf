/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:01:58 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/03 21:02:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
**	else
**		ft_switch3(c, ap, *&com);
**
**	static void	ft_switch3(char c, va_list ap, t_com **com)
**	{
**		if (c == 'e')
**			ft_do_e((*com)->var.db = va_arg(ap, double), *&com);
**		else if (c == 'E')
**			ft_do_ee((*com)->var.db = va_arg(ap, double), *&com);
**		else if (c == 'f')
**			ft_do_f((*com)->var.db = va_arg(ap, double), *&com);
**		else if (c == 'F')
**			ft_do_ff((*com)->var.db = va_arg(ap, double), *&com);
**		else if (c == 'g')
**			ft_do_g((*com)->var.d = va_arg(ap, double), *&com);
**		else if (c == 'G')
**			ft_do_gg((*com)->var.d = va_arg(ap, double), *&com);
**		else if (c == 'a')
**			ft_do_a((*com)->var.d = va_arg(ap, double), *&com);
**		else if (c == 'A')
**			ft_do_aa((*com)->var.d = va_arg(ap, double), *&com);
**		else if (c == 'n')
**			ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
**		else if (c == 'b')
**			ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
**		else if (c == 'r')
**			ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
**		else if (c == 'k')
**			ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
**	}
*/

static void	ft_switch2(char c, va_list ap, t_com **com)
{
	if (c == 'X')
		ft_switch_oux(ap, *&com, 16, 1);
	else if (c == 'c')
		ft_do_c((*com)->var.c = va_arg(ap, int), *&com);
	else if (c == 'C')
		ft_do_c((*com)->var.c = va_arg(ap, int), *&com);
}

void		ft_switch(char c, va_list ap, t_com **com)
{
	if (c == 's')
		ft_do_s((*com)->var.s = va_arg(ap, char*), *&com);
//	else if (c == 'S')
//		ft_do_ss((*com)->var.s = va_arg(ap, char*), *&com);
	else if (c == 'p')
		ft_do_p((*com)->var.p = va_arg(ap, void *), *&com);
	else if (c == 'd')
		ft_switch_d(ap, *&com);
	else if (c == 'D')
		ft_do_dd((*com)->var.l = va_arg(ap, long int), *&com);
	else if (c == 'i')
		ft_switch_d(ap, *&com);
	else if (c == 'o')
		ft_switch_oux(ap, *&com, 8, 0);
	else if (c == 'O')
		ft_do_oo((*com)->var.l = va_arg(ap, long int), *&com);
	else if (c == 'u')
		ft_switch_oux(ap, *&com, 10, 0);
	else if (c == 'U')
		ft_do_uu((*com)->var.l = va_arg(ap, long int), *&com);
	else if (c == 'x')
		ft_switch_oux(ap, *&com, 16, 0);
	else
		ft_switch2(c, ap, *&com);
}
