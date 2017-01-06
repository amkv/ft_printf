/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:51:15 by akalmyko          #+#    #+#             */
/*   Updated: 2017/01/06 14:51:18 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** ***** cut *********  PRECISION  ****************************************
*/

static unsigned char	*ft_strdupn_wchar(const unsigned char *s1, size_t n)
{
	unsigned char	*result;
	unsigned char	*temp;

	if (!s1)
		return (NULL);
	result = (unsigned char*)malloc(sizeof(unsigned char) * n + 1);
	temp = result;
	if (result != NULL)
	{
		while (*s1 && n > 0)
		{
			*temp++ = *s1++;
			n--;
		}
		*temp = '\0';
		return (result);
	}
	else
		return (NULL);
}

static void		ft_mod_cut_wchar_word(t_com **com, size_t precision)
{
	unsigned char	*result;
	wchar_t			*copy;
	size_t 			len;
	size_t 			temp;

	copy = (*com)->var.ws;
	len = 0;
	while (*copy)
	{
		if (len < precision)
		{
			temp = ft_wcharlen(*copy);
			if ((temp + len) > precision)
				break ;
			len += temp;
			copy++;
		}
		else
			break ;
	}
	result = ft_strdupn_wchar((*com)->w_scroll, len);
	free((*com)->w_scroll);
	(*com)->w_scroll = NULL;
	(*com)->w_scroll = result;
	(*com)->len = len;
}

void			ft_mod_cut_word(t_com **com, size_t precision)
{
	char		*result;

	if ((*com)->modifier && *(*com)->modifier == 'S')
	{
		ft_mod_cut_wchar_word(*&com, precision);
		return ;
	}
	if (!(*com)->scroll || !(*com)->modifier)
		return ;
	if (*(*com)->modifier == 'x' || *(*com)->modifier == 'X'
		|| *(*com)->modifier == 'd' || *(*com)->modifier == 'i')
		return ;
	result = ft_strdupn((*com)->scroll, precision);
	ft_free_and_set(&(*com)->scroll, &result);
	(*com)->len = precision;
}
