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

static void	ft_switch3(char c, va_list ap, t_com **com)
{
	if (c == 'n')
		ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
//	else if (c == 'b') // не своя функция
//		ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
//	else if (c == 'r') // не своя функция
//		ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
//	else if (c == 'k') // не своя функция
//		ft_do_n((*com)->var.s = va_arg(ap, char*), *&com);
}

static void	ft_switch2(char c, va_list ap, t_com **com)
{
	if (c == 'X')
		ft_do_xx((*com)->var.u = va_arg(ap, unsigned int), *&com);
	else if (c == 'c')
		ft_do_c((*com)->var.c = va_arg(ap, int), *&com);
	else if (c == 'C') // не своя функция
		ft_do_c((*com)->var.c = va_arg(ap, int), *&com);
	else if (c == 'e')
		ft_do_e((*com)->var.db = va_arg(ap, double), *&com);
	else if (c == 'E')
		ft_do_ee((*com)->var.db = va_arg(ap, double), *&com);
	else if (c == 'f')
		ft_do_f((*com)->var.db = va_arg(ap, double), *&com);
	else if (c == 'F')
		ft_do_ff((*com)->var.db = va_arg(ap, double), *&com);
	else if (c == 'g')
		ft_do_g((*com)->var.d = va_arg(ap, double), *&com);
	else if (c == 'G')
		ft_do_gg((*com)->var.d = va_arg(ap, double), *&com);
	else if (c == 'a')
		ft_do_a((*com)->var.d = va_arg(ap, double), *&com);
	else if (c == 'A')
		ft_do_aa((*com)->var.d = va_arg(ap, double), *&com);
	else
		ft_switch3(c, ap, *&com);
}

void		ft_switch_d(va_list ap, t_com **com)
{
	if (*(*com)->length == 'h' && (*(*com)->length + 1) == 'h')
		ft_do_d((*com)->var.sc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_d((*com)->var.sh = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && (*(*com)->length + 1) == 'l')
		ft_do_d((*com)->var.ll = va_arg(ap, long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_d((*com)->var.lo = va_arg(ap, long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_d((*com)->var.it = va_arg(ap, intmax_t), *&com);
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_d((*com)->var.d = va_arg(ap, int), *&com);
}

void		ft_switch(char c, va_list ap, t_com **com)
{
	if (c == 's')														// OK
		ft_do_s((*com)->var.s = va_arg(ap, char*), *&com);
	else if (c == 'S')													// .
		ft_do_ss((*com)->var.s = va_arg(ap, char*), *&com);
	else if (c == 'p')													// OK
		ft_do_p((*com)->var.p = va_arg(ap, void *), *&com);
	else if (c == 'd') 													// не OK
		ft_switch_d(ap, *&com);
	else if (c == 'D')													// .
		ft_do_dd((*com)->var.l = va_arg(ap, long int), *&com);
	else if (c == 'i') 													// OK
		ft_do_d((*com)->var.i = va_arg(ap, int), *&com);
	else if (c == 'o')													// OK
		ft_do_o((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (c == 'O')													// .
		ft_do_o((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (c == 'u')													// .OK unsigned int // проверить диапазоны
		ft_do_u((*com)->var.u = va_arg(ap, unsigned int), *&com);
	else if (c == 'U')													// .
		ft_do_uu((*com)->var.u = va_arg(ap, unsigned int), *&com);
	else if (c == 'x')
		ft_do_x((*com)->var.u = va_arg(ap, unsigned int), *&com);
	else
		ft_switch2(c, ap, *&com);
}
