/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:51:29 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/23 13:05:00 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * write, malloc, free, exit
 * void va_start(va_list ap, last);
 * type va_arg(va_list ap, type);
 * void va_copy(va_list dest, va_list src);
 * void va_end(va_list ap);
 *
 * new functions:
 * ft_atoi_base.c
 * ft_numlen.c
 *
 */

#include "../libftprintf.h"

static void	ft_p(int mr, int or)
{
		printf("\nm: %d\no: %d\n- - - - - - - - - \n", mr, or);
}

int			main(void)
{
	int 	mr = 0;
	int 	or = 0;

//	mr = ft_printf("");
//	printf("\n");
//	or =    printf("");
//	ft_p(mr, or);
//
//	mr = ft_printf("a");
//	printf("\n");
//	or =    printf("a");
//	ft_p(mr, or);
//
//	mr = ft_printf("1");
//	printf("\n");
//	or =    printf("2");
//	ft_p(mr, or);
//
//	mr = ft_printf("a1");
//	printf("\n");
//	or =    printf("a1");
//	ft_p(mr, or);
//
//	mr = ft_printf("1a");
//	printf("\n");
//	or =    printf("1a");
//	ft_p(mr, or);
//
//	mr = ft_printf(" ");
//	printf("\n");
//	or =    printf(" ");
//	ft_p(mr, or);
//
//	mr = ft_printf("\tt");
//	printf("\n");
//	or =    printf("\tt");
//	ft_p(mr, or);
//
//	mr = ft_printf("number%d", 5);
//	printf("\n");
//	or =    printf("number%d", 5);
//	ft_p(mr, or);
//
//	mr = ft_printf("number/%d", 6);
//	printf("\n");
//	or =    printf("number/%d", 6);
//	ft_p(mr, or);

	mr = ft_printf("number\%%d", 7);
//	printf("\n");
//	or =    printf("number\%%d", 7);
//	ft_p(mr, or);

	mr = ft_printf("teststring%d%shello%s", 1, "second", "third");
	printf("\n");
	or =    printf("teststring%d%shello%s", 1, "second", "third");
	ft_p(mr, or);

	return (0);
}

