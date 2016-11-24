/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:27:48 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/05 15:27:49 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;
	t_list	*next_list;

	if (alst && del)
	{
		next_list = *alst;
		while (next_list)
		{
			(*del)(next_list->content, (*next_list).content_size);
			temp = next_list->next;
			free(next_list);
			next_list = temp;
		}
		*alst = NULL;
	}
}
