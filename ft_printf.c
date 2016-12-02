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



int 				ft_printf(const char * restrict format, ...)
{
//	va_list ap;
	int counter;
	int	arguments;
	t_com *list;
//	t_list *arg;
//	char *str;

	counter = 0;
	arguments = 0;
	list = NULL;
	if (*format == '\0')
		return (counter);
	arguments = ft_parser(format, &list);
	printf("a: %d\n", arguments);
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
	ft_tcom_print(list);
	ft_tcom_free(list);
	return (counter);
}
