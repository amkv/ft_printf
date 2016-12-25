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
	if (str == NULL)
	{
		(*com)->scroll = ft_strdup("(null)");
		(*com)->len = 6;
		return ;
	}
	else if (*str == '\0')
	{
		free((*com)->scroll);
		(*com)->scroll = NULL;
		(*com)->scroll = ft_strdup("");
		(*com)->len = 0;
		return ;
	}
	else
	{
		free((*com)->scroll);
		(*com)->scroll = NULL;
		(*com)->scroll = ft_strdup(str);
		(*com)->len = ft_strlen((*com)->scroll);
	}
}

void		ft_do_ss(wchar_t *str, t_com **com)
{
	unsigned int	len;

	if (str == NULL)
	{
		(*com)->w_scroll = (unsigned char*)ft_strdup("(null)");
		(*com)->len = 6;
		return ;
	}
	(*com)->w_scroll = wchar_str(str, &len);
	(*com)->len = len;
}

void		ft_do_c(char c, t_com **com)
{
	c = 0;
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = ft_strnew(1);
	(*com)->len = 1;
}

void		ft_do_cc(wchar_t c, t_com **com)
{
	unsigned int	len;

	if (c == 0)
	{
		ft_do_c(0, *&com);
		return ;
	}
	(*com)->w_scroll = wchar_chr(c, &len);
	(*com)->len = len;
}

void		ft_do_p(void *ptr, t_com **com)
{
	char	*temp;

	free((*com)->scroll);
	(*com)->scroll = NULL;
	temp = ft_itoa_base((long int)*&ptr, 16);
	if (ptr == NULL)
		(*com)->scroll = ft_strjoin(temp, "x0");
	else
		(*com)->scroll = ft_strjoin("0x", temp);
	free(temp);
	(*com)->len = ft_strlen((*com)->scroll);
}
