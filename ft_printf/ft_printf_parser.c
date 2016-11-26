/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:32 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 20:00:33 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int ft_parser(const char *format, t_list **list)
{
	int 	arg;
	t_list	*new;
	char	*temp;

	arg = 0;
	new = NULL;
	*list = NULL;
	temp = (char*)format;
	while (*format != '%')
	{

		format++;
	}
	return (arg);
}

//static void ft_get_argument(t_list *list)
//{
//
//}