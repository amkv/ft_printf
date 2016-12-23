/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:31:14 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:31:15 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_switch_d(va_list ap, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	if ((*com)->length == NULL)
		ft_do_d((*com)->var.d = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_d_hh((*com)->var.sc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_d_h((*com)->var.sh = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_d_ll((*com)->var.ll = va_arg(ap, long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_d_l((*com)->var.lo = va_arg(ap, long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_d_j((*com)->var.it = va_arg(ap, intmax_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_d_z((*com)->var.zu = va_arg(ap, unsigned long int), *&com);
	(*com)->len = ft_strlen((*com)->scroll);
}

void		ft_switch_oux(va_list ap, t_com **com, int base, int yesno)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
	if ((*com)->length == NULL)
		ft_do_oux((*com)->var.o = va_arg(ap, unsigned int), *&com, base);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_oux_hh((*com)->var.uc = va_arg(ap, int), *&com, base);
	else if (*(*com)->length == 'h')
		ft_do_oux_h((*com)->var.us = va_arg(ap, int), *&com, base);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_oux_ll(
				(*com)->var.ull = va_arg(ap, unsigned long long), *&com, base);
	else if (*(*com)->length == 'l')
		ft_do_oux_l((*com)->var.ul = va_arg(ap, unsigned long), *&com, base);
	else if (*(*com)->length == 'j')
		ft_do_oux_j((*com)->var.ut = va_arg(ap, uintmax_t), *&com, base);
	else if (*(*com)->length == 'z')
		ft_do_oux_z((*com)->var.zu = va_arg(ap, size_t), *&com, base);
	(*com)->len = ft_strlen((*com)->scroll);
	if (yesno == 1)
		ft_mod_string_to_upper((*com)->scroll, *&com);
}
