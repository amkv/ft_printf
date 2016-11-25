/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:25:39 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/24 13:46:16 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_printf(const char * restrict format, ...)
{
	va_list ap;

	va_start(ap, format);
	printf("%s\n", format);
	while (*format != '\0')
	{
		while((*format != '%') && *format != '\0')
			ft_putchar(*format++);
		if (*format == '\0')
			break;
		if (*format == '%')
			format++;
		if (*format == '%')
			ft_putchar('%');
		if (*format == 's')
			ft_putstr(va_arg(ap, char *));
		else if (*format == 'd')
			ft_putnbr(va_arg(ap, int));
		else if (*format == 'c')
			ft_putchar(va_arg(ap, int));
		format++;
	}
	va_end(ap);
	return (1);
}
