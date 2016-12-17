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

/* ************************************************************************** */

void			ft_free_and_set(char **old, char **new)
{
	free(*old);
	*old = NULL;
	*old = *new;
}

/* ************************************************************************** */

void			ft_putstrn(const char *str, size_t n)
{
	while (*str && n > 0)
	{
		ft_putchar(*str);
		n--;
	}
}

/* ************************************************************************** */

char 			*ft_strnew_spaces(size_t len, char c)
{
	char 		*result;
	char 		*temp;

	result = ft_strnew(len);
	if (!result)
		return (NULL);
	temp = result;
	while(len > 0)
	{
		*temp++ = c;
		len--;
	}
	return (result);
}

/* ************************************************************************** */

static int		ft_add_spaces_helper(t_com **com)
{
	char		c;

	if (!(*com)->modifier)
		return (0);
	c = *(*com)->modifier;
	if (c == 'd' || c == 'x' || c == 'o')
	{
		if ((*com)->flag && *(*com)->flag == '0')
			return (1);
	}
	return (0);
}

void 			ft_add_spaces(t_com **com)
{
	char 		*result;
	char 		*spaces;
	size_t 		width;
	size_t 		len;

	if (!(*com)->width)
		return ;
	width = (size_t)ft_atoi((*com)->width);
	len = (*com)->len;
	if (len >= width)
		return ;
	if (ft_add_spaces_helper(*&com) == 1)
		spaces = ft_strnew_spaces(width - len, '0');
	else
		spaces = ft_strnew_spaces(width - len, ' ');
	if ((*com)->flag && *(*com)->flag == '-')
	{
		result = ft_strjoin((*com)->scroll, spaces);
		(*com)->width = NULL;
	}
	else
		result = ft_strjoin(spaces, (*com)->scroll);
	free(spaces);
	free((*com)->scroll);
	(*com)->scroll = NULL;
	(*com)->scroll = result;
	(*com)->len = width;
}

/* ************************************************************************** */

static int 		ft_add_0x_helper(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'n' || c == 'p' ||
			c == 's' || c == 'u')
		return (1);
	return (0);
}

void			ft_add_0x(t_com **com)
{
	char 		*beg;
	char 		*result;

	if (ft_atoi((*com)->scroll) == 0 || !(*com)->modifier ||
			ft_add_0x_helper(*(*com)->modifier) == 1)
		return ;
	else if (*(*com)->modifier == 'x')
		beg = ft_strdup("0x");
	else if (*(*com)->modifier == 'X')
		beg = ft_strdup("0X");
	else if (*(*com)->modifier == 'o')
		beg = ft_strdup("0");
	else
		return ;
	result = ft_strjoin(beg, (*com)->scroll);
	free(beg);
	free((*com)->scroll);
	(*com)->scroll = result;
	(*com)->len = ft_strlen(result);
}

/* ************************************************************************** */

void			ft_string_to_upper(char *str, t_com **com)
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

/* ************************************************************************** */