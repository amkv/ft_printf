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
	printf("\nm: %d\no: %d\n- - - - - - - - - \n", mr, or);
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
	mr = ft_printf("%  +d", 42);
	printf("\n");
	or = printf("%  +d", 42);
	printf("\n");
	ft_p(mr, or);
	return (0);
}
