/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_do_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 19:01:43 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/20 19:01:44 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_do_s(char *str, t_com **com)
{
	char	*result;

	if (str == NULL)
	{
		(*com)->scroll = ft_strdup("(null)");
		(*com)->len = 6;
		return ;
	}
	result = ft_strdup(str);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(str);
}

//void		ft_do_ss(char *str, t_com **com)
//{
//	return ;
//}

void		ft_do_c(char c, t_com **com)
{
	free((*com)->scroll);
	(*com)->scroll = NULL;
//	c = ' ';
	(*com)->scroll = ft_strnew(1);
	(*com)->len = 1;
}

void		ft_do_p(void *ptr, t_com **com)
{
	char	*temp;

	free((*com)->scroll);
	(*com)->scroll = NULL;
	temp = ft_itoa_base((long int)*&ptr, 16);
	(*com)->scroll = ft_strjoin("0x", temp);
	free(temp);
	(*com)->len = ft_strlen((*com)->scroll);
}
