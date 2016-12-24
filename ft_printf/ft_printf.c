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

#include "../libftprintf.h"

//static int			ft_exceptions(const char *format, int *characters)
//{
//	int				index;
//
//	*characters = 0;
//	if ((*format == '\0') || (*format == '%' && *(format + 1) == '\0'))
//		return (*characters);
//	if (*format == '%' && *(format + 1) == '%' && *(format + 2) == '\0')
//	{
//		ft_putchar('%');
//		return (++(*characters));
//	}
//	if (*format == '%' && *(format + 1) == ' ')
//	{
//		index = 1;
//		while (format[index] == ' ')
//			index++;
//		if (format[index] == '%' && format[index + 1] == '\0')
//		{
//			ft_putchar('%');
//			return ((*characters = 1));
//		}
//	}
///*
//	if (*format == '%')
//	{
//		index = 1;
//		while (ft_isdigit(format[index]) == 1)
//			index++;
//		if (format[index] == '%' && format[index + 1] == '\0')
//		{
//			while (index > 0)
//			{
//				ft_putchar(' ');
//				index--;
//			}
//			ft_putchar('%');
//			*characters = index;
//			return (*characters);
//		}
//	}
// */
//	return (-1);
//}

static void			ft_print_result(t_com *com, int *characters)
{
	t_com			*copy;

	copy = com;
	*characters = 0;
	while (copy != NULL)
	{
		if (copy->modifier && (*copy->modifier == 'c' ||  *copy->modifier == 'C')
			&& copy->type == '%')
		{
			if (copy->flag && *copy->flag == '-')
			{
				ft_putchar(copy->var.c);
				ft_putstrn(copy->scroll, ((copy->len) - 1));
			}
			else
			{
				ft_putstrn(copy->scroll, ((copy->len) - 1));
				ft_putchar(copy->var.c);
			}
		}
		else
			ft_putstr(copy->scroll);
		*characters += copy->len;
		copy = copy->next;
	}
}

static void			ft_pre_printing(t_com *com, va_list ap, size_t argc)
{
	t_com			*copy;

	copy = com;
	argc = 0; // перегрузка значения
	while (copy != NULL)
	{
		if (copy->type == '%')
		{
			if (copy->width && *copy->width == '*')
			{
				free(copy->width);
				copy->width = ft_itoa(va_arg(ap, int));
			}
			if (copy->precision && *copy->precision == '*')
			{
				free(copy->precision);
				copy->precision = ft_itoa(va_arg(ap, int));
			}
			ft_switch(*(copy)->modifier, ap, &copy);
			ft_pre_print_null_precision(&copy);
		}
		ft_pre_print(&copy);
		copy = copy->next;
	}
}

int					ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_com			*com;
	size_t			argc;
	int				characters;

//	if (ft_exceptions(format, &characters) >= 0)
//		return (characters);
	characters = 0; // удалить
	argc = 0; // удалить
	va_start(ap, format);
	ft_parser(format, &com, &argc);
//	printf("аргументов: %zu\n", argc);
//	ft_tcom_print(com, 0);
	ft_pre_printing(*&com, ap, argc);
//	ft_tcom_print(com, 1);
	ft_print_result(*&com, &characters);
	ft_tcom_free_all(com);
	va_end(ap);
	return (characters);
}
