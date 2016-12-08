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

//static void	ft_tcom_null_terminating(t_com **com, int i)
//{
//	while (i < PLEN)
//	{
//		(*com)->param[i] = 0;
//		(*com)->flag[i] = 0;
//		(*com)->width[i] = 0;
//		(*com)->precision[i] = 0;
//		(*com)->length[i] = 0;
//		i++;
//	}
//}

t_com		*ft_tcom_new(char type, char *command)
{
	t_com	*new;

	if (!(new = (t_com*)malloc(sizeof(t_com) * 1)))
		return (NULL);
	if (type == '%')
	{
		new->command = command;
		new->scroll = NULL;
		new->size = 0;
		new->len = 0;
	}
	else
	{
		new->command = NULL;
		new->scroll = command;
		new->size = sizeof(command);
		new->len = ft_strlen(command);
	}
	new->type = type;
	new->size = 0;
	new->next = NULL;
//	ft_tcom_null_terminating(&new, 0);
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
		if (tmp->type == '%')
		{
			free(tmp->command);
			free(tmp->scroll);
		}
		else
			free(tmp->scroll);
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
		printf("%c\n", tmp->type);
		printf("%s\n", tmp->command);
		printf("%s\n", tmp->scroll);
		tmp = tmp->next;
	}
}
