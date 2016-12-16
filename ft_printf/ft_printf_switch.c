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

static void	ft_switch3(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 'n')
		ft_do_n(type->s = va_arg(ap, char*), *&com);
//	else if (c == 'b') // не своя функция
//		ft_do_n(type->s = va_arg(ap, char*), *&com);
//	else if (c == 'r') // не своя функция
//		ft_do_n(type->s = va_arg(ap, char*), *&com);
//	else if (c == 'k') // не своя функция
//		ft_do_n(type->s = va_arg(ap, char*), *&com);
}

static void	ft_switch2(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 'X')
		ft_do_xx((type)->d = va_arg(ap, int), *&com);
	else if (c == 'c')
		ft_do_c((type)->c = va_arg(ap, int), *&com);
	else if (c == 'C') // не своя функция
		ft_do_c((type)->c = va_arg(ap, int), *&com);
	else if (c == 'e')
		ft_do_e(type->db = va_arg(ap, double), *&com);
	else if (c == 'E')
		ft_do_ee(type->db = va_arg(ap, double), *&com);
	else if (c == 'f')
		ft_do_f(type->db = va_arg(ap, double), *&com);
	else if (c == 'F')
		ft_do_ff(type->db = va_arg(ap, double), *&com);
	else if (c == 'g')
		ft_do_g(type->d = va_arg(ap, double), *&com);
	else if (c == 'G')
		ft_do_gg(type->d = va_arg(ap, double), *&com);
	else if (c == 'a')
		ft_do_a(type->d = va_arg(ap, double), *&com);
	else if (c == 'A')
		ft_do_aa(type->d = va_arg(ap, double), *&com);
	else
		ft_switch3(c, *&type, ap, *&com);
}

void		ft_switch(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 's')
		ft_do_s(type->s = va_arg(ap, char*), *&com);
	else if (c == 'S')
		ft_do_ss(type->s = va_arg(ap, char*), *&com);
	else if (c == 'p')
		ft_do_p((type)->p = va_arg(ap, void *), *&com);
	else if (c == 'd')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	else if (c == 'D') // не своя функция
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	else if (c == 'i') // не своя функция
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	else if (c == 'o')
		ft_do_o((type)->uo = va_arg(ap, unsigned int), *&com);
	else if (c == 'O') // не своя функция
		ft_do_o((type)->uo = va_arg(ap, unsigned int), *&com);
	else if (c == 'u')
		ft_do_u((type)->ui = va_arg(ap, unsigned int), *&com);
	else if (c == 'U')
		ft_do_uu((type)->ui = va_arg(ap, unsigned int), *&com);
	else if (c == 'x')
		ft_do_x((type)->d = va_arg(ap, int), *&com);
	else
		ft_switch2(c, *&type, ap, *&com);
}
