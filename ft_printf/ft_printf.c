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

static void			ft_print_result(t_com *com, int *characters)
{
	t_com			*copy;

	copy = com;
	while (copy != NULL)
	{
		if (copy->modifier && (*copy->modifier == 'c')
			&& copy->type == '%')
		{
			if (copy->flag && *copy->flag == '-')
			{
				ft_putchar(copy->var.c);
				ft_putstrn(copy->scroll, ((copy->len) - 1));
			}
			else if (ft_atoi(copy->width) < 0)
			{
				ft_putchar(copy->var.c);
				ft_putstr(copy->scroll);
			}
//			else if (ft_isprint(copy->var.c))
//			{
//				ft_putchar('h');
//				ft_putstr(copy->scroll);
//			}
			else
			{
				ft_putstrn(copy->scroll, ((copy->len) - 1));
				ft_putchar(copy->var.c);
			}
		}
		else if (copy->modifier &&
				(*copy->modifier == 'S' || *copy->modifier == 'C'))
		{
			if (ft_strchr_qt(copy->flag, '-') > 0)
			{
				ft_putwstr(copy->w_scroll);
				ft_putstr(copy->scroll);
			}
			else
			{
				ft_putstr(copy->scroll);
				ft_putwstr(copy->w_scroll);
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
				copy->prec_flag = 1;
			}
			ft_switch(*(copy)->modifier, ap, &copy);
			ft_pre_print_null_precision(&copy);
		}
		ft_pre_print_precision(&copy);
		ft_pre_print_flags(&copy);
		ft_pre_print_width(&copy);
		copy = copy->next;
	}
}

int					ft_printf(const char *restrict format, ...)
{
	va_list			ap;
	t_com			*com;
	size_t			argc;
	int				characters;

	argc = 0; // удалить
	characters = 0;
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
