/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:39:15 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/28 10:39:16 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_com		*ft_tcom_new(char type, char *command)
{
	t_com	*new;

	if (!(new = (t_com*)malloc(sizeof(t_com) * 1)))
		return (NULL);
	new->scroll = command;
	new->size = sizeof(command);
	new->len = ft_strlen(command);
	new->ptr = NULL;

	new->type = type;
	new->param = NULL;
	new->flag = NULL;
	new->width = 0;
	new->precision = NULL;
	new->length = NULL;
	new->modifier = NULL;

	new->next = NULL;
	return (new);
}

void		ft_tcom_add(t_com **beg, t_com *next)
{
	if (*beg && next)
	{
		next->next = *beg;
		*beg = next;
	}
}

t_com		*ft_tcom_revert(t_com **list)
{
	t_com	*tmp;
	t_com	*revers;
	t_com	*save;
	int		yesno;

	yesno = 0;
	tmp = *list;
	save = NULL;
	while (tmp)
	{
		revers = tmp->next;
		if (yesno++ == 0)
			tmp->next = NULL;
		else
			tmp->next = save;
		save = tmp;
		tmp = revers;
	}
	*list = save;
	return (save);
}

void		ft_tcom_free(t_com *list)
{
	t_com	*tmp;
	t_com	*next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;

		free(tmp->scroll);
		free(tmp->ptr);

		free(tmp->param);
		free(tmp->flag);
//		free(tmp->width);
		free(tmp->precision);
		free(tmp->length);
		free(tmp->modifier);

		free(tmp);
		tmp = next;
	}
}

void		ft_tcom_print(t_com *list)
{
	t_com	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("scroll:   %s\n", tmp->scroll);
		printf("size:     %zu\n", tmp->size);
		printf("len:      %zu\n", tmp->len);
		printf("type:     %c\n", tmp->type);
		printf("param:    %s\n", tmp->param);
		printf("flag:     %s\n", tmp->flag);
		printf("width:    %lu\n", tmp->width);
		printf("precision:%s\n", tmp->precision);
		printf("length:   %s\n", tmp->length);
		printf("modifier: %s\n\n", tmp->modifier);

		tmp = tmp->next;
	}
}
