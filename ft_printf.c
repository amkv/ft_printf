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



int 				ft_printf(const char * restrict format, ...)
{
//	va_list ap;
	int counter;
	t_list *list;
//	t_list *arg;
//	char *str;

	counter = 0;
	if (*format == '\0')
		return (counter);
	ft_parser(format, &list);
//	va_start(ap, format);
//	while ((arg = ft_get_arg(&list)) != NULL) {
//		str = arg->data;
//		if (ft_check_command(*str) == 0) {
//			counter = counter + (int) ft_strlen(str);
//			ft_putstr(str);
//		} else
//			counter += ft_processing(str, va_arg(ap, void *));
//	}
//	va_end(ap);
	return (counter);
}
