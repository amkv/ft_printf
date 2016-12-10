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

static void	ft_switch2(char c, union u_type *type, va_list ap, t_com **com)
{

	if (c == 'F')
		ft_do_F(type->d = va_arg(ap, double), *&com);
	if (c == 'e')
		ft_do_e(type->d = va_arg(ap, double), *&com);
	if (c == 'E')
		ft_do_E(type->d = va_arg(ap, double), *&com);
	if (c == 'g')
		ft_do_g(type->d = va_arg(ap, double), *&com);
	if (c == 'G')
		ft_do_G(type->d = va_arg(ap, double), *&com);
	if (c == 'a')
		ft_do_a(type->d = va_arg(ap, double), *&com);
	if (c == 'A')
		ft_do_A(type->d = va_arg(ap, double), *&com);
	if (c == 'n')
		ft_do_n(type->s = va_arg(ap, char*), *&com);
//	if (c == 's')
//		ft_do_s(type->s = va_arg(ap, char*), *&com);
//	if (c == 's')
//		ft_do_s(type->s = va_arg(ap, char*), *&com);
//	else
//		ft_switch3(c, *&type, ap, *&com);
}

void		ft_switch(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 's')
		ft_do_s(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_do_S(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_do_c((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	if (c == 'p')
		ft_do_p((type)->p = va_arg(ap, void *), *&com);
	if (c == 'x') // проверить тип на unsigned int
		ft_do_x((type)->d = va_arg(ap, int), *&com);
	if (c == 'X') // проверить тип на unsigned int
		ft_do_X((type)->d = va_arg(ap, int), *&com);
	if (c == 'u')
		ft_do_u((type)->ui = va_arg(ap, unsigned int), *&com);
	if (c == 'o') // не сделано
		ft_do_o((type)->ui = va_arg(ap, unsigned int), *&com);
	if (c == 'f')
		ft_do_f(type->d = va_arg(ap, double), *&com);
	else
		ft_switch2(c, *&type, ap, *&com);
}
