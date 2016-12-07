/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:09:41 by akalmyko          #+#    #+#             */
/*   Updated: 2016/12/06 15:09:42 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
//#define ABS(v) ((v < 0) ? : -(v) : (v))
//
//static void	ft_aux(int value, int base, char *result, int *index)
//{
//	char 	b[] = "0123456789ABCDEF";
//
//	if (value <= -base || base <= value)
//		ft_aux((value / base), base, result, index);
//	result[(*index)++] = (char)b[ABS(value % base)];
//}
//
//char 		*ft_itoa_base(int value, int base)
//{
//	char 	*result;
//	int 	index;
//
//	if (base < 2 || base > 16 || !(result = ft_strnew(35)))
//		return (NULL);
//	index = 0;
//	if (base == 10 && value < 0)
//		result[index++] = '-';
//	ft_aux(value, base, result, &index);
//	result[index] = '\0';
//	return (result);
//}
