/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:51:29 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/30 12:01:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** write, malloc, free, exit
** void va_start(va_list ap, last);
** type va_arg(va_list ap, type);
** void va_copy(va_list dest, va_list src);
** void va_end(va_list ap);
*/

#include "../libftprintf.h"

static void		ft_p(int mr, int or)
{
	printf("\nm: %d\no: %d\n- - - - - - - - - \n", mr, or);
}

int				main(void)
{
	int			mr;
	int			or;

	mr = ft_printf("billy%s%d%c", "henry", 2, '!');
	printf("\n");
	or = printf("billy%s%d%c", "henry", 2, '!');
	ft_p(mr, or);
	return (0);
}
