/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:01 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 20:03:34 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			ft_free_and_set(char **old, char **new)
{
	free(*old);
	*old = NULL;
	*old = *new;
}

void			ft_putstrn(const char *str, size_t n)
{
	if (str)
	{
		while (*str && n > 0)
		{
			ft_putchar(*str);
			n--;
		}
	}
}

char			*ft_strnew_char_filled(size_t len, char c)
{
	char		*result;
	char		*temp;

	result = ft_strnew(len + 1);
	if (!result)
		return (NULL);
	temp = result;
	while (len-- > 0)
		*temp++ = c;
	*temp = '\0';
	return (result);
}

char			*ft_strjoin_and_free(char *str1, char *str2, int a, int b)
{
	char		*result;

	if (!str1 || !str2)
		return (NULL);
	if (!(result = ft_strjoin(str1, str2)))
		return (NULL);
	if (a > 0)
	{
		free(str1);
		str1 = NULL;
	}
	if (b > 0)
	{
		free(str2);
		str2 = NULL;
	}
	return (result);
}

void			ft_mod_string_to_upper(char *str, t_com **com)
{
	char		*temp;
	char		*result;
	char		*copy;

	temp = str;
	result = ft_strnew(ft_strlen(str) + 1);
	if (result == NULL)
		return ;
	copy = result;
	while (*temp)
	{
		*copy = (char)ft_toupper(*temp);
		copy++;
		temp++;
	}
	*copy = '\0';
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}
