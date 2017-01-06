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
#include <stdio.h>

static void		ft_p(int mr, int or)
{
	printf("\nm: %d\no: %d\n\n--------/\\-------\n", mr, or);
	printf(" |  ft_printf  | ");
	printf("\n-----------------\n");
	printf("| output order: |\n| m - my printf |\n| o - original  |");
	printf("\n-----------------");
}

int				main(void)
{
	int			mr;
	int			or;
	char		*str;

	str = "hello";
	mr = 0;
	or = 0;
	setlocale(LC_ALL, "en_GB");
	mr = ft_printf("");
	printf("\n");
	or = printf("");
	ft_p(mr, or);
	return (0);
}
