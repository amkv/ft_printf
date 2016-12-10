/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:56:25 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 19:56:26 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#' || c == '\'')
		return (1);
	return (0);
}

int 	ft_is_width(char c)
{
	if (c == '*')
		return (1);
	return (0);
}

int		ft_is_precision(char c)
{
	if (c == '.' || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

int		ft_is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' || c == 'z' || c == 'j' || c == 't')
		return (1);
	return (0);
}

int		ft_is_modifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'f' || c == 'F' || c == 'e'
		|| c == 'E' || c == 'g' || c == 'G' || c == 'x' || c == 'X'
		|| c == 'o' || c == 's' || c == 'c' || c == 'p' || c == 'a'
		|| c == 'A' || c == 'n')
		return (1);
	return (0);
}
