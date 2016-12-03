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
	size_t 		counter;
	;
	counter = 0;
	if (something == NULL)
		return (0);
	if ((*com)->type == 's')
	{
		s = (char*)something;
		write(1, &s, ft_strlen(s));
		counter = (*com)->len;
	}
	return (counter);
}

static size_t	ft_switcher(t_com **list, void *something)
{
	t_com		*copy;
	size_t 		characters;

	copy = *list;
	characters = 0;
	if ((copy->type) != '%')
	{
		ft_putstr(copy->command);
		characters = copy->len;
	}
	else
	{
		characters = ft_processing(*&list, something);
		if (characters == 0)
			return (0);
	}
	return (characters);
}

static size_t	ft_printf_printf(va_list ap, t_com **commands, size_t argc)
{
	size_t 		characters;
	size_t 		arguments;

	characters = 0;
	arguments = 0;
	argc = 0; // что-нибудь с этим сделать
	while (*commands != NULL)
	{
		printf("\nloop: %zu\n", arguments);
		characters = ft_switcher(*&commands, va_arg(ap, void *));
//		if (characters == 0)
//			return (characters);
		characters += characters;
		*commands = (*commands)->next;
		arguments++;
	}
	return (characters);
}

int 			ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	t_com		*commands;
	t_com		*copy;
	size_t 		argc;
	size_t		characters;

	commands = NULL;
	characters = 0;
	if (*format == '\0')
		return (0);
	va_start(ap, format);
	ft_parser(format, &commands, &argc);
	copy = commands;
//	printf("a: %zu\n", argc);
//	ft_tcom_print(commands);
	characters = ft_printf_printf(ap, &commands, argc);
	ft_tcom_free(copy);
	va_end(ap);
	return ((int)characters);
}
