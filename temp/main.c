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
 *
 *
 * how to add new modifier?
 *
 * ft_do_XXX
 * ft_switch_XXX
 * ft_is_modifier..if
 * +add union type
*/

#include "../libftprintf.h"
#include "math.h"

static void		ft_p(int mr, int or)
{
	printf("\nm: %d\no: %d\n- - - - - - - - - \n", mr, or);
}

int				main(void)
{
	int			mr;
	int			or;
	char 		*str;
	char 		c;

	str = "hello";
	mr = 0; or = 0;

	mr = ft_printf("%u", "4294967295");
	printf("\n");
	or = printf("%e\n", -16123123123.1);
	or = printf("%e\n", 16123123123.1);
	or = printf("%e\n", -0.1345231231);
	or = printf("%e\n", 0.1345231231);

	printf("\n");
	ft_p(mr, or);

	c = 0;
	write(1, &c, 1);

	return (0);

// мертвые кейсы...
//	mr = ft_printf("%-5%test");
//	mr = ft_printf("%2c", 0);

}
