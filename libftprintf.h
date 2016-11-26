/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:13:45 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/24 13:24:39 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h> // delete

int 	ft_printf(const char * restrict format, ...);
int 	ft_numlen(int num);
int		ft_is_flag(char c);
int 	ft_is_width(char c);
int 	ft_is_precision(char c);
int 	ft_is_length(char c);
int 	ft_is_type(char c);
int 	ft_parser(const char *format, t_list **list);

//int		ft_atoi_base(char *str, char *base);

#endif
