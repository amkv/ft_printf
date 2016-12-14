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

//static int 	ft_check_modifier(const char *str)
//{
//	while (*str)
//	{
//		if (ft_is_modifier(*str) == 1)
//			return (1);
//		str++;
//	}
//	return (0);
//}

static void	ft_tcom_list(t_com **list, t_com *fresh)
{
	if (*list == NULL)
		*list = fresh;
	else
		ft_tcom_add(*&list, fresh);
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
			if (**str == '%' && *(*str + 1) == '\0')
				(*len)++;
		}
	if (*yn > 0)
		(*beg)++;
}

void	ft_check_patterns(t_com **com, size_t *yn, char **holder, size_t *argc) // структура, булеан есть ли %, стринг отрезанной команды
{
	char 	*copy;	// переменная для сравнения начального состояния *holder и конечного, сохраняю адрес на первую ячейку в памяти
	t_com	*fresh; // новый чистый лист для манипуляций
	char 	*newholder;

	copy = ft_strdup(*holder);
	// создаю новый чистый лист
	fresh = ft_tcom_fresh();
	// если модификаторов во время распиливания стринга не обнаружилось
	// создаю простой лист для печати
	if (*yn == 0)
	{
		fresh->scroll = *holder;
		fresh->len = ft_strlen(*holder);
		ft_tcom_list(*&com, fresh);
		return ;
	}
	// заношу все данные в лист
	(fresh)->param = ft_pat_parameter(*&holder);
	(fresh)->flag = ft_pat_flags(*&holder);
	(fresh)->width = ft_pat_width(*&holder);
//	(fresh)->precision = ft_pat_precision(*&holder);
//	(fresh)->length =  ft_is_lenght(*&holder);
	(fresh)->modifier = ft_pat_modifier(*&holder);
	if ((fresh)->modifier == NULL && *holder) // добавить проверку на нулевой холдер
		(fresh)->scroll = ft_strdup(*holder);
	else
	{
		(fresh)->type = '%';
		(*argc)++;
	}
	// добавляю лист в цепочку
	ft_tcom_list(*&com, fresh);


	// проверяю остаток в *holder
	if (*holder == NULL)
		return ;
	if (ft_strcmp(copy, *holder) != 0)
	{
		newholder = ft_strdup(*holder);
		fresh->scroll = newholder;
		fresh->len = ft_strlen(newholder);
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

//void	ft_check_patterns(t_com **com, size_t *yn, )
//{
//	char 	*holder;
//	char 	*temp;
//
//	if (*yn == 0 || ft_pat_one(*&com) == 1)
//		return ;
//	holder = ft_strdup((*com)->scroll);
//	temp = ft_strdup((*com)->scroll);
//
//	free((*com)->scroll);
//	(*com)->scroll = NULL;
//	(*com)->len = 0;
//
//	(*com)->param = ft_pat_parameter(&holder);
//	(*com)->flag = ft_pat_flags(&holder);
//	(*com)->width = ft_pat_width(&holder);
//	(*com)->precision = ft_pat_precision(&holder);
////	(*com)->length =  ft_is_lenght(&holder);
//	(*com)->modifier = ft_pat_modifier(&holder);
//	if ((*com)->modifier == NULL)
//		(*com)->type = '.';
//
//	if (holder && ft_strcmp(temp, holder) != 0) // ||
//		ft_tcom_list(*&com, 0, holder);
//	free(temp);
//}