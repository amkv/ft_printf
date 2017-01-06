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

static void		ft_print_result_c(t_com *copy)
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
	else
	{
		ft_putstrn(copy->scroll, ((copy->len) - 1));
		ft_putchar(copy->var.c);
	}
}

static void		ft_print_result_sc(t_com *copy)
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

static void		ft_print_result(t_com *copy, int *characters)
{
	char		*m;

	while (copy != NULL)
	{
		if ((m = copy->modifier) && *m == 'c' && copy->type == '%')
			ft_print_result_c(*&copy);
		else if (m && (*m == 'S' || *m == 'C'))
			ft_print_result_sc(*&copy);
		else
			ft_putstr(copy->scroll);
		*characters += copy->len;
		copy = copy->next;
	}
}

static void		ft_pre_printing(t_com *copy, va_list ap)
{
	while (copy != NULL)
	{
		if (copy->type == '%')
		{
			if (copy->width && *copy->width == '*')
			{
				free(copy->width);
				copy->width = ft_itoa(va_arg(ap, int));
				copy->width_flag = 1;
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

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_com		*com;
	t_com		*copy;
	int			characters;

	characters = 0;
	va_start(ap, format);
	ft_parser(format, &com);
	copy = com;
	ft_pre_printing(*&copy, ap);
	copy = com;
	ft_print_result(*&copy, &characters);
	ft_tcom_free_all(com);
	va_end(ap);
	return (characters);
}
