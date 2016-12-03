/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:25:39 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/30 12:01:40 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


static size_t 	ft_processing(t_com **com, void *something)
{
	char 		*s;
//	char 		c;
//	int 		d;
	t_com		*copy;
	size_t 		ccounter;

	copy = *com;
	ccounter = 0;
	if (copy->type == 's')
	{
		s = (char*)something;
		write(1, &s, ft_strlen(s));
	}
	return (ccounter);
}

static size_t	ft_switcher(t_com **list, void *something)
{
	t_com		*copy;
	size_t 		ccounter;

	copy = *list;
	ccounter = 0;
	if ((copy->type) != '%')
	{
		ft_printf("%s", copy->command);
		ccounter = copy->len;
	}
	else
		ccounter = ft_processing(*&list, something);
	return (ccounter);
}

static size_t	ft_printf_print(va_list **ap, const char *format, t_com **commands)
{
	size_t 		counter;

	counter = 0;

	va_start(*ap, format);
	while (*commands != NULL)
	{
		counter = ft_switcher(*&commands, va_arg(*ap, void *));
		counter += counter;
		commands = *commands->next;
	}
	va_end(ap);

	return (counter);
}

int 			ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	t_com		*commands;
	size_t 		arg;
	size_t		counter;

	arg = 0;
	commands = NULL;
	if (*format == '\0')
		return ((int)counter);
	arg = (int)ft_parser(format, &commands); printf("a: %zu\n", arg);
	counter = ft_printf_print(&ap, format, &commands);
//	ft_tcom_print(commands);
	ft_tcom_free(commands);
	return ((int)counter);
}

