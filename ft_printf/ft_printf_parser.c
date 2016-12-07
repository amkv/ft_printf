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

static void	ft_tcom_list(t_com **list, size_t yn, char *holder)
{
	char	sign;

	if (yn > 0)
		sign = '%';
	else
		sign = '.';
	if (*list == NULL)
		*list = ft_tcom_new(sign, holder);
	else
		ft_tcom_add(*&list, ft_tcom_new(sign, holder));
}

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
		}
	if (*yn > 0)
		(*beg)++;
}

//static void	ft_get_arg(char **str, size_t *beg, size_t *yn, size_t *len)
//{
//	char 	*copy;
//
//
//	*yn = 0;
//	*len = 0;
//	if (**str == '%')
//	{
//		(*yn)++;
//		(*str)++;
//	}
//	copy = *str;
//	if (**str == '%')
//		(*len) = 1;
//	else
//		while (*copy != '\0')
//		{
//			if (*copy == '%'  && *(copy + 1) == '%')
//				copy++;
//			if (*copy == '%'  && *(copy + 1) != '%' && *(copy + 1) != '\0')
//				break;
//			(*len)++;
//			copy++;
//		}
//	if (*yn > 0)
//		(*beg)++;
//	*str = copy;
//}

static void	ft_second_check(t_com **com, char **holder, size_t *yn)
{
	char	*copy;
	char 	*new;
	char 	*hold;
	int 	number;

	if (*yn == 0)
		return ;
	copy = *holder;
	if (*copy == '%')
		*yn = 0;
	if (ft_strlen(copy) == 1)
		return ;
	number = ft_atoi(copy);
	printf("%d", number);
	if (ft_is_type(*copy) == 1)
	{
		ft_memcpy((hold = ft_strnew(2)), copy, 1);
		ft_tcom_list(*&com, *yn, hold);
	}
	new = ft_strdup(++copy);
	free(*holder);
	*holder = new;
	*yn = 0;
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
		ft_second_check(*&com, &holder, &yn);
		ft_tcom_list(*&com, yn, holder);
		(*argc)++;
	}
}
