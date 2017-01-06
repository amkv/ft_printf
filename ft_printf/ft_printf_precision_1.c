/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:32:04 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/04 19:32:06 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ******* pre print precision *******************************************
*/

void			ft_pre_print_precision(t_com **com)
{
	size_t		pre_ion;
	signed long	pre_cion;
	size_t		len;
	char		*mod;

	if (!(*com)->precision || !(mod = (*com)->modifier))
		return ;
	if ((*com)->var.c != 0 && (*mod == 'c' || *mod == 'C'))
	{
		free((*com)->scroll);
		(*com)->scroll = ft_strdup("*");
		*mod = 's';
		return ;
	}
	if ((pre_cion = ft_atoi((*com)->precision)) < 0)
		return;
	pre_ion = (size_t)pre_cion;
	len = (*com)->len;
	if ((*mod == 'd' || *mod == 'i') && (*com)->var.d < 0)
	{
		if (pre_ion < len - 1)
			ft_mod_cut_word(*&com, pre_ion);
		else if (pre_ion > len - 1)
			ft_mod_extend_word(*&com, pre_ion, len);
	}
	if (pre_ion == 0 && (*mod == 's' || *mod == 'S'))
	{
		free((*com)->scroll);
		(*com)->scroll = NULL;
		(*com)->len = 0;
		(*com)->scroll = ft_strnew(1);
	}
//	if (*mod == 'p')
//	{
//		if (!(*com)->scroll)
//			;
//	}
	if ((pre_ion == 0)
		|| ((*com)->scroll && *(*com)->scroll == '\0')
		|| (*mod == 'p' && pre_ion < len)
		|| ((*mod == 'u' || *mod == 'U') && pre_ion < len)
		|| (*mod == 's' && pre_ion >= len)
		|| ((*mod == 'o' || *mod == 'O') && pre_ion < len))
		return ;
	else if (pre_ion < len)
		ft_mod_cut_word(*&com, pre_ion);
	else if (pre_ion > len)
		ft_mod_extend_word(*&com, pre_ion, len);
}
