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
#include <locale.h>

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

	setlocale(LC_ALL, "en_GB");

//	mr = ft_printf("{%03.2d}", 0);
//	printf("\n");
//	mr = ft_printf("%03.2d", 0);
//	printf("\n");
//	or = printf("{%03.2d}", 0);
//	printf("\n");
//	or = printf("%03.2d", 0);

	mr = ft_printf("%03.2d", -1);
	printf("\n");
	or = printf("%03.2d", -1);

//	"%03.2d", 0
//	"{%03.2d}", 0
//	printf("\nlen1: %zu\n", ft_wcharlen(L'我'));
//	printf("len2: %zu", ft_wstrlen(L"我是一只猫。"));

	ft_p(mr, or);
	return (0);
}

/*
004
 04
m: 3
o: 3
*/





