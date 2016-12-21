
#include "../libftprintf.h"

void		ft_switch_d(va_list ap, t_com **com)
{
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
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_d_z((*com)->var.zu = va_arg(ap, unsigned long int), *&com);
}

void		ft_switch_o(va_list ap, t_com **com)
{
	if ((*com)->length == NULL)
		ft_do_o((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_o_hh((*com)->var.uc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_o_h((*com)->var.us = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_o_ll((*com)->var.ull = va_arg(ap, unsigned long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_o_l((*com)->var.ul = va_arg(ap, unsigned long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_o_j((*com)->var.ut = va_arg(ap, uintmax_t), *&com);
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_o_z((*com)->var.zu = va_arg(ap, size_t), *&com);
	return ;
}

void		ft_switch_x(va_list ap, t_com **com)
{
	if ((*com)->length == NULL)
		ft_do_x((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_x_hh((*com)->var.uc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_x_h((*com)->var.us = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_x_ll((*com)->var.ull = va_arg(ap, unsigned long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_x_l((*com)->var.ul = va_arg(ap, unsigned long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_x_j((*com)->var.ut = va_arg(ap, uintmax_t), *&com);
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_x_z((*com)->var.zu = va_arg(ap, size_t), *&com);
	return ;
}

void		ft_switch_xx(va_list ap, t_com **com)
{
	if ((*com)->length == NULL)
		ft_do_xx((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_xx_hh((*com)->var.uc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_xx_h((*com)->var.us = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_xx_ll((*com)->var.ull = va_arg(ap, unsigned long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_xx_l((*com)->var.ul = va_arg(ap, unsigned long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_xx_j((*com)->var.ut = va_arg(ap, uintmax_t), *&com);
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_xx_z((*com)->var.zu = va_arg(ap, size_t), *&com);
	return ;
}

void		ft_switch_u(va_list ap, t_com **com)
{
	if ((*com)->length == NULL)
		ft_do_u((*com)->var.o = va_arg(ap, unsigned int), *&com);
	else if (*(*com)->length == 'h' && *((*com)->length + 1) == 'h')
		ft_do_u_hh((*com)->var.uc = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'h')
		ft_do_u_h((*com)->var.us = va_arg(ap, int), *&com);
	else if (*(*com)->length == 'l' && *((*com)->length + 1) == 'l')
		ft_do_u_ll((*com)->var.ull = va_arg(ap, unsigned long long), *&com);
	else if (*(*com)->length == 'l')
		ft_do_u_l((*com)->var.ul = va_arg(ap, unsigned long), *&com);
	else if (*(*com)->length == 'j')
		ft_do_u_j((*com)->var.ut = va_arg(ap, uintmax_t), *&com);
//	else if (*(*com)->length == 't')
//		ft_do_d((*com)->var.pt = va_arg(ap, ptrdiff_t), *&com);
	else if (*(*com)->length == 'z')
		ft_do_u_z((*com)->var.zu = va_arg(ap, size_t), *&com);
	return ;
}
