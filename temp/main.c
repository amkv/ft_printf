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
 */

#include "../libftprintf.h"

int			main(void)
{
	char	*s;
	char	c;
	int 	d;

	s = "test3";
	d = 42;
	c = 'K';

	ft_putstr("putstr: test\n");
	printf("printf: test2\n");
	printf("- - - - - - - - - - -\n");
	ft_printf("%s", s);
	ft_printf("%c", c);
	ft_printf("%d", d);
	return (0);
}

