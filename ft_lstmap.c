/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:34:42 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/05 15:34:43 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*result;
	t_list		*beg;
	t_list		*temp;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(result = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	beg = result;
	while (lst->next)
	{
		temp = f(lst->next);
		if (!(result->next = ft_lstnew(temp->content, temp->content_size)))
		{
			ft_lstdel(&beg, &ft_bzero);
			return (NULL);
		}
		lst = lst->next;
		result = result->next;
	}
	return (beg);
}
