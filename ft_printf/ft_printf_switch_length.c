
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

//test