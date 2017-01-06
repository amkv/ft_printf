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

static void	ft_get_no_modifier(char **str, size_t *len, int *scob, int *beg)
{
	(*len) += (*beg);
	*str = (*str + *beg);
	if (**str == '%')
	{
		(*len)++;
		(*str)++;
	}
	if ((*scob) > 0)
	{
		(*len) -= 1;
		--(*str);
	}
}

static void	ft_get_true_percent(char **str, size_t *len)
{
	int		counter;
	int		beg;
	int		scob;

	counter = 0;
	beg = 0;
	scob = 0;
	while ((*(*str + beg) != '\0') && *(*str + beg) != '%')
	{
		if (ft_is_modifier(*(*str + beg)) == 1)
			counter++;
		if (*(*str + beg) == '}')
			scob++;
		beg++;
	}
	if (counter == 0)
		ft_get_no_modifier(*&str, *&len, &scob, &beg);
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '}')
				break ;
		}
}

static void	ft_get_arg(char **str, size_t *beg, size_t *yn, size_t *len)
{
	*yn = 0;
	*len = 0;
	if (**str == '{')
	{
		(*len)++;
		(*str)++;
		return ;
	}
	if (**str == '%')
	{
		(*yn)++;
		(*str)++;
		ft_get_true_percent(*&str, *&len);
	}
	else
		while (**str != '%' && **str != '\0')
		{
			(*len)++;
			(*str)++;
			if (**str == '}')
				break ;
		}
	if (*yn > 0)
		(*beg)++;
}

static void	ft_check_patterns(
			t_com **com, size_t *yn, char **holder)
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
	(fresh)->precision = ft_pat_precision(*&holder);
	(fresh)->length = ft_pat_length(*&holder);
	(fresh)->modifier = ft_pat_modifier(*&holder);
	ft_pat_ending(&fresh, *&holder);
	ft_tcom_list(*&com, fresh);
	if (*holder == NULL)
		return (free(copy));
	else
		ft_pat_string(*&com, &copy, *&holder);
}

void		ft_parser(const char *format, t_com **com)
{
	char	*copy;
	char	*holder;
	size_t	beg;
	size_t	yn;
	size_t	len;

	*com = NULL;
	beg = 0;
	copy = (char*)format;
	while (*copy != '\0')
	{
		ft_get_arg(&copy, &beg, &yn, &len);
		if (*copy == '\0' && len == 0)
			break ;
		ft_memnncpy((holder = ft_strnew(len + 1)), format, beg, len);
		beg += len;
		ft_check_patterns(*&com, &yn, &holder);
	}
	ft_tcom_revert(*&com);
}
