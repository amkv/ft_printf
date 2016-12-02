/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:32 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/30 12:01:37 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int			ft_parser(const char *format, t_com **list)
{
	int		arg;
	size_t	len;
	size_t	start;
	size_t	counter;
	char	sign;
	char	*format_copy;
	char	*holder;

	arg = 0;
	start = 0;
	holder = NULL;
	format_copy = (char*)format;
	while (*format != '\0')
	{
		len = 0;
		counter = 0;
		holder = NULL;

		if (*format == '%')
		{
			counter++;
			format++;
		}
		if (*format == '%')
			len = 1;
		else
			while (*format != '%' && *format != '\0')
			{
				len++;
				format++;
			}

		if (*format == '\0' && len == 0)
			return (arg);
		if (counter > 0)
			start++;
		if (counter > 0)
			sign = '%';
		else
			sign = '.';


		ft_memnncpy((holder = ft_strnew(len + 1)), format_copy, start, len);
//		*(holder + len) = '\0';

		start += len;

		if (*list == NULL)
			*list = ft_tcom_new(sign, holder);
		else
			ft_tcom_add(*&list, ft_tcom_new(sign, holder));

		arg++;
	}
	ft_tcom_revert(*&list);
	return (arg);
}
