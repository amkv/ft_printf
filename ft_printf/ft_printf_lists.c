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
	new->size = 0;
	new->len = 0;
	new->ptr = NULL;
	new->type = '.';
	new->param = NULL;
	new->flag = NULL;
	new->width = 0;
	new->precision = NULL;
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
//	int 		counter;

	yesno = 0;
//	counter = 0;
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
//		tmp->counter = ++counter;
		tmp = revers;

	}
	*list = save;
}

void			ft_tcom_free_first(t_com **list)
{
	t_com		*next;
	t_com		*victim;

	next = (*list)->next->next;
	victim = (*list)->next;
	free(victim->scroll);
	free(victim->ptr);
	free(victim->param);
	free(victim->flag);
	free(victim->width);
	free(victim->precision);
	free(victim->length);
	free(victim->modifier);
	free(victim);
	(*list)->next = next;
}

void			ft_tcom_free_next(t_com **list)
{
	t_com		*next;
	t_com		*victim;

	next = (*list)->next->next;
	victim = (*list)->next;
	free(victim->scroll);
	free(victim->ptr);
	free(victim->param);
	free(victim->flag);
	free(victim->width);
	free(victim->precision);
	free(victim->length);
	free(victim->modifier);
	free(victim);
	(*list)->next = next;
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
		free(tmp->ptr);
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

static void		ft_tcom_print2(t_com *list, int yesno)
{
	if (yesno != 1 || list->modifier == NULL || list->type == '.')
	{
		printf("var:       ...\n\n");
		return ;
	}
	if (*list->modifier == 's')
		printf("var s:     %s\n", list->var.s);
	else if (*list->modifier == 'p')
		printf("var p:     %p\n", list->var.p);
	else if (*list->modifier == 'd')
		printf("var d:     %d\n", list->var.d);
	else if (*list->modifier == 'D')
		printf("var l:     %ld\n", list->var.l);
	else if (*list->modifier == 'i')
		printf("var i:     %i\n", list->var.i);
	else if (*list->modifier == 'o')
		printf("var o:     %i\n", list->var.o);
	else if (*list->modifier == 'u')
		printf("var u:     %i\n", list->var.u);
	else if (*list->modifier == 'x')
		printf("var x:     %i\n", list->var.u);
	else if (*list->modifier == 'X')
		printf("var X:     %i\n", list->var.u);
	printf("\n");
}

void			ft_tcom_print(t_com *list, int yesno)
{
	t_com		*tmp;

	tmp = list;
	while (tmp)
	{
		printf("scroll:    \'%s\'\n", tmp->scroll);
		printf("size:      \'%zu\'\n", tmp->size);
		printf("len:       \'%zu\'\n", tmp->len);
		printf("type:      \'%c\'\n", tmp->type);
		printf("param:     \'%s\'\n", tmp->param);
		printf("flag:      \'%s\'\n", tmp->flag);
		printf("width:     \'%s\'\n", tmp->width);
		printf("precision: \'%s\'\n", tmp->precision);
		printf("length:    \'%s\'\n", tmp->length);
		printf("modifier:  \'%s\'\n", tmp->modifier);
		printf("counter:   \'%d\'\n", tmp->counter);
		ft_tcom_print2(tmp, yesno);
		tmp = tmp->next;
	}
}
