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

#include "../libftprintf.h"

static void		ft_p(int mr, int or)
{
	printf("\nm: %d\no: %d\n\n--------/\\-------\n", mr, or);
	printf(" |  ft_printf  | ");
	printf("\n-----------------\n");
	printf("| output order: |\n| m - my printf |\n| o - original  |");
	printf("\n-----------------");
}

/*
** 	or = printf("%S", 100); MEMORY
** 	mr = ft_printf("%10m33", str); // создает два листа
** 	or = printf("%e\n", -16123123123.1);
** 	or = printf("%e\n", -0.1345231231);
** 	or = printf("%e\n", 0.1345231231);
** 	mr = ft_printf("%.10x", 42);
*/

int				main(void)
{
	int			mr;
	int			or;
	char		*str;

	str = "hello";
	mr = 0;
	or = 0;

//	mr = ft_printf("%010x", 542);
//	"%#08x", 42
//	mr = ft_printf("%3.0p", 12345678);
	mr = ft_printf("%4.s", "42");
	printf("\n");
	or = printf("%4.s", "42");
	ft_p(mr, or);
	return (0);
}

/*
printf("%.4o", 424242);
printf("%15.4o", 424242);
printf("%8.4o", 424242424);
printf("%4.8o", 424242424);
*/





