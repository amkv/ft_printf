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

char 	*ft_is_parameter(char **holder)
{
	char	*copy;
	int 	len;

	copy = *holder;
	len = 0;
	while (ft_isdigit(*copy) == 1)
	{
		copy++;
		len++;
	}
	if (len > 0 && *copy == '$')
		return (NULL);
	return (NULL);
}


int		ft_is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == 'o' || c == '#')
		return (1);
	return (0);
}

char		*ft_is_width(char **holder)
{
	char 	*copy;

	copy = *holder;

	if (**holder == '*')
		return (NULL);

//	if (c == '*' || ft_isdigit(c) == 1)
//		return (1);
	return (NULL);
}

char 		*ft_is_string(char **holder)
{
	return (*holder);
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
