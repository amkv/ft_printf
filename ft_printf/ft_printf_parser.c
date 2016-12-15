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

static void	ft_get_arg(char **str, size_t *beg, size_t *yn, size_t *len)
{
	*yn = 0;
	*len = 0;
	if (**str == '%')
	{
		(*yn)++;
		(*str)++;
	}
	if (**str == '%')
		(*len) = 1;
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '%' && *(*str + 1) == '\0')
				(*len)++;
		}
	if (*yn > 0)
		(*beg)++;
}

void		ft_check_patterns(t_com **com, size_t *yn, char **holder, size_t *argc)
{
	char	*copy;
	t_com	*fresh;

	fresh = ft_tcom_new();
	if (ft_pat_one(*&com, &fresh, *&holder, *&yn) == 1)
		return ;
	copy = ft_strdup(*holder);
	(fresh)->param = ft_pat_parameter(*&holder);
	(fresh)->flag = ft_pat_flags(*&holder);
	(fresh)->width = ft_pat_width(*&holder);
//	if (*(fresh)->width == '*')
//	{
//		ft_tcom_list(*&com, ft_tcom_new());
//		(*com)->width = ft_strdup("*");
//		(*com)->modifier = ft_strdup("d");
//		(*com)->type = '%';
//	}
	(fresh)->precision = ft_pat_precision(*&holder);
	(fresh)->length =  ft_pat_length(*&holder);
	(fresh)->modifier = ft_pat_modifier(*&holder);

	if ((fresh)->modifier == NULL && *holder)
	{
		(fresh)->scroll = ft_strdup(*holder);
		(fresh)->len = ft_strlen((fresh)->scroll);
		free(*holder);
		*holder = NULL;
	}
	else
	{
		(fresh)->type = '%';
		(*argc)++;
	}
	ft_tcom_list(*&com, fresh);




	if (*holder == NULL)
	{
		free(copy);
		return ;
	}

	if (ft_strcmp(copy, *holder) != 0)
	{
		fresh = ft_tcom_new();
		fresh->scroll = ft_strdup(*holder);
		fresh->len = ft_strlen(fresh->scroll);
		ft_tcom_list(*&com, fresh);
	}
	free(copy);
}

void		ft_parser(const char *format, t_com **com, size_t *argc)
{
	char	*copy;
	char	*holder;
	size_t	beg;
	size_t	yn;
	size_t	len;

	*argc = 0;
	*com = NULL;
	beg = 0;
	copy = (char*)format;
	while (*copy != '\0')
	{
		ft_get_arg(&copy, &beg, &yn, &len);
		if (*copy == '\0' && len == 0)
			return ;
		ft_memnncpy((holder = ft_strnew(len + 1)), format, beg, len);
		beg += len;
		ft_check_patterns(*&com, &yn, &holder, *&argc);
	}
}
