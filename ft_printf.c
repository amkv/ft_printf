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

static int		ft_exceptions(const char *format, int *characters)
{
	int 		index;

	*characters = 0;
	if ((*format == '\0') || (*format == '%' && *(format + 1) == '\0'))
		return (*characters);
	if (*format == '%' && *(format + 1) == '%' && *(format + 2) == '\0')
	{
		ft_putchar('%');
		return (++(*characters));
	}
	if (*format == '%' && *(format + 1) == ' ')
	{
		index = 1;
		while (format[index] == ' ')
			index++;
		if (format[index] == '%' && format[index + 1] == '\0')
		{
			ft_putchar('%');
			return ((*characters = 1));
		}
	}
	return (-1);
}

static void		ft_print_result(t_com *com, int *characters)
{
	t_com		*copy;

	copy = com;
	*characters = 0;
	while (copy != NULL)
	{
		ft_putstr(copy->scroll);
		*characters += copy->len;
		copy = copy->next;
	}
}

static void			ft_pre_printing(t_com *com, va_list ap, size_t argc)
{
	t_com			*copy;
	char 			*modifier;
	union u_type	type;

	copy = com;
	argc = 0;
	while (copy != NULL)
	{
		if (copy->type == '%')
		{
			modifier = copy->modifier;
			ft_switch(*modifier, &type, ap, &copy);
			ft_pre_print_width(&copy);
		}
		copy = copy->next;
	}
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_com		*com;
	size_t		argc;
	int		characters;

	if (ft_exceptions(format, &characters) >= 0)
		return (characters);
	va_start(ap, format);
	ft_parser(format, &com, &argc);
	ft_tcom_revert(&com);
//	printf("a: %zu\n", argc);
//	ft_tcom_print(com);
	ft_pre_printing(*&com, ap, argc);
//	ft_tcom_print(com);
	ft_print_result(*&com, &characters);
	ft_tcom_free(com);
	va_end(ap);
	return (characters);
}
