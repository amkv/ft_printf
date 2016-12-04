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

//static void	ft_p(int mr, int or)
//{
//		printf("\nm: %d\no: %d\n- - - - - - - - - \n", mr, or);
//}

int			main(void)
{
//	int 	mr = 0;
//	int 	or = 0;
	int 	len;

//	mr = ft_printf("test%d%shello%s", 1, "second", "third");
//	mr = ft_printf("test%BIG");
//	printf("\n-----------------");
//	or =    printf("test%d%shello%s", 1, "second", "third");
//	or = printf("%");
//	ft_p(mr, or);

//	len = ft_printf("test%d%c", 10, '#');
	len = ft_printf("%s%s%d%c", "test", "desk", 10, '!');
	printf("\nlen: %d", len);
	return (0);
}

