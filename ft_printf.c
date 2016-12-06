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

static size_t	ft_handler(t_com **com, va_list ap)
{
	char			*command;
	char			z;
	union u_type	type;

	command = (*com)->command;
	z = *command;
	ft_switch(z, &type, ap, *&com);
//	ft_do_something(z, &type);
	return ((*com)->len);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_com		*com;
	t_com		*dupl;
	size_t		argc;
	size_t		characters;

	if (*format == '\0')
		return (0);
	characters = 0;
	va_start(ap, format);
	ft_parser(format, &com, &argc);
	dupl = ft_tcom_revert(&com);
//	printf("a: %zu\n", argc);
//	ft_tcom_print(com);
	while (com != NULL)
	{
		if (com->type == '%')
			ft_handler(&com, ap);
		ft_putstr(com->scroll);
		characters += com->len;
		com = com->next;
	}
	ft_tcom_free(dupl);
	va_end(ap);
	return ((int)characters);
}
