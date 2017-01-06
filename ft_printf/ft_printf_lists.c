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

static void		ft_tcom_add(t_com **beg, t_com *next)
{
	if (*beg && next)
	{
		next->next = *beg;
		*beg = next;
	}
}

t_com			*ft_tcom_new(void)
{
	t_com		*new;
	static int	counter;

	if (!(new = (t_com*)malloc(sizeof(t_com) * 1)))
		return (NULL);
	new->scroll = NULL;
	new->w_scroll = NULL;
	new->len = 0;
	new->type = '.';
	new->param = NULL;
	new->flag = NULL;
	new->width = 0;
	new->width_flag = -1;
	new->precision = NULL;
	new->prec_flag = -1;
	new->length = NULL;
	new->modifier = NULL;
	new->next = NULL;
	new->counter = ++counter;
	return (new);
}

void			ft_tcom_list(t_com **list, t_com *fresh)
{
	if (*list == NULL)
		*list = fresh;
	else
		ft_tcom_add(*&list, fresh);
}

void			ft_tcom_revert(t_com **list)
{
	t_com		*tmp;
	t_com		*revers;
	t_com		*save;
	long int	yesno;

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
}

void			ft_tcom_free_all(t_com *list)
{
	t_com		*tmp;
	t_com		*next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->scroll);
		free(tmp->w_scroll);
		free(tmp->param);
		free(tmp->flag);
		free(tmp->width);
		free(tmp->precision);
		free(tmp->length);
		free(tmp->modifier);
		free(tmp);
		tmp = next;
	}
}
