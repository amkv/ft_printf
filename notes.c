/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:31:08 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/25 15:31:10 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "libftprintf.h"


int 		ft_numlen(int num)
{
	int 	len;

	len = 0;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int 				ft_printf(const char * restrict format, ...)
{
	va_list 		ap;
//	va_list 		tmp;
	int				counter;
	char			*temp;
	int				num;
//	unsigned int	unum;
//	unsigned char	*uchar;

//	printf("%s", format);

	counter = 0;
	if (*format == '\0')
		return (counter);
	va_start(ap, format);
//	tmp = ap;
//	va_copy(tmp, ap);

//	printf("%p", va_arg(ap, char *));
//	printf("\n");

//	printf("%s", (char*)ap->reg_save_area);
// 	printf("%p", (char*)ap->next);

//	printf("%s", va_arg(ap, char *));
//	printf("\n");
//	printf("%s", va_arg(ap, char *));
//	printf("\n");
//	printf("%s", va_arg(ap, char *));
//	printf("\n");
//	printf("%s", va_arg(ap, char *));
//	printf("\n");
//	while ((va_arg(tmp)) != NULL)
//		counter++;
//
////
	while (*format != '\0')
	{
		/* печатаю символы идущие до символа % , сдвигаюсь вправо по строке*/
		while((*format != '%') && *format != '\0')
		{
			ft_putchar(*format++);
			counter++;
		}
		/* если строка закончилась, то выхожу из функции */
		if (*format == '\0')
			break;
		/* если нахожу символ % обрабатываю второй символ $ - печатая его, двигаюсь вправо */
		if (*format == '%')
			format++;
		if (*format == '%')
		{
			ft_putchar('%');
			counter++;
		}
		/* начинаю проверку на символы */
		/* если это строка */
		if (*format == 's')
		{
			temp = (va_arg(ap, char *));
			counter = counter + (int)ft_strlen(temp);
			ft_putstr(temp);
		}
			/* если это номер */
		else if (*format == 'd')
		{
			num = va_arg(ap, int);
			counter = counter + ft_numlen(num);
			ft_putnbr(num);
		}
			/* если это символ */
		else if (*format == 'c')
		{
			ft_putchar(va_arg(ap, int));
			counter++;
		}
		/* если это unsigned int как шестнадцатиричное число */
//		else if (*format == 'x')
//		{
//			uchar = va_arg(ap, unsigned char *);
//			unum = ft_atoi_base(uchar, 16);
//			uchar = itoa(unum);
//			counter = counter + (int)ft_strlen(uchar);
//			ft_putstr(uchar);
//		}
		format++;
	}
	va_end(ap);
	return (counter);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (*format != '\0')
	{
		/* печатаю символы идущие до символа % , сдвигаюсь вправо по строке*/
		while((*format != '%') && *format != '\0')
		{
			ft_putchar(*format++);
			counter++;
		}
		/* если строка закончилась, то выхожу из функции */
		if (*format == '\0')
			break;
		/* если нахожу символ % обрабатываю второй символ $ - печатая его, двигаюсь вправо */
		if (*format == '%')
			format++;
		if (*format == '%')
		{
			ft_putchar('%');
			counter++;
		}
		/* начинаю проверку на символы */
		/* если это строка */
		if (*format == 's')
		{
			temp = (va_arg(ap, char *));
			counter = counter + (int)ft_strlen(temp);
			ft_putstr(temp);
		}
		/* если это номер */
		else if (*format == 'd')
		{
			num = va_arg(ap, int);
			counter = counter + ft_numlen(num);
			ft_putnbr(num);
		}
		/* если это символ */
		else if (*format == 'c')
		{
			ft_putchar(va_arg(ap, int));
			counter++;
		}
		/* если это unsigned int как шестнадцатиричное число */
//		else if (*format == 'x')
//		{
//			uchar = va_arg(ap, unsigned char *);
//			unum = ft_atoi_base(uchar, 16);
//			uchar = itoa(unum);
//			counter = counter + (int)ft_strlen(uchar);
//			ft_putstr(uchar);
//		}
		format++;
	}
	va_end(ap);
	return (counter);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////