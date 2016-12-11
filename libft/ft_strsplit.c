/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:15:03 by akalmyko          #+#    #+#             */
/*   Updated: 2016/10/03 19:26:25 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_word(const char *str, int i, char **ret, char c)
{
	int			len;
	int			space;

	space = 0;
	len = 0;
	while (*str == c)
	{
		str++;
		space++;
	}
	while (str[len] && str[len] != c)
		len++;
	if (len > 0)
	{
		ret[i] = ft_strnew(len);
		ft_strncpy(ret[i], str, len);
	}
	return (space + len);
}

static int		ft_count_words(const char *str, int i, char c)
{
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int			len;
	char		**ret;
	int			i;
	int			wc;

	if (!s)
		return (NULL);
	wc = ft_count_words(s, 0, c);
	len = 0;
	ret = (char **)ft_memalloc((wc + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		len = ft_find_word(s, i++, ret, c);
		s += len;
	}
	ret[wc] = 0;
	return (ret);
}
