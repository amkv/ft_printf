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
static void	ft_switch3(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 's')
		ft_resize_string(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_test(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_char_bla((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'u')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 's')
		ft_resize_string(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_test(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_char_bla((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
}

static void	ft_switch2(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 's')
		ft_resize_string(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_test(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_char_bla((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'u')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 's')
		ft_resize_string(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_do_S(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_do_c((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_int_bla((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	else
		ft_switch3(c, *&type, ap, *&com);
}
*/

void		ft_switch(char c, union u_type *type, va_list ap, t_com **com)
{
	if (c == 's')
		ft_resize_string(type->s = va_arg(ap, char*), *&com);
	if (c == 'S')
		ft_do_S(type->s = va_arg(ap, char*), *&com);
	if (c == 'c')
		ft_do_c((type)->c = va_arg(ap, int), *&com);
	if (c == 'd')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	if (c == 'i')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	if (c == 'u')
		ft_do_d((type)->d = va_arg(ap, int), *&com);
	if (c == 'p')
		ft_do_p((type)->p = va_arg(ap, void *), *&com);
}
