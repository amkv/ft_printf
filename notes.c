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

/* main tests */

//	mr = ft_printf("");
//	printf("\n");
//	or =    printf("");
//	ft_p(mr, or);
//
//	mr = ft_printf("a");
//	printf("\n");
//	or =    printf("a");
//	ft_p(mr, or);
//
//	mr = ft_printf("1");
//	printf("\n");
//	or =    printf("2");
//	ft_p(mr, or);
//
//	mr = ft_printf("a1");
//	printf("\n");
//	or =    printf("a1");
//	ft_p(mr, or);
//
//	mr = ft_printf("1a");
//	printf("\n");
//	or =    printf("1a");
//	ft_p(mr, or);
//
//	mr = ft_printf(" ");
//	printf("\n");
//	or =    printf(" ");
//	ft_p(mr, or);
//
//	mr = ft_printf("\tt");
//	printf("\n");
//	or =    printf("\tt");
//	ft_p(mr, or);
//
//	mr = ft_printf("number%d", 5);
//	printf("\n");
//	or =    printf("number%d", 5);
//	ft_p(mr, or);
//
//	mr = ft_printf("number/%d", 6);
//	printf("\n");
//	or =    printf("number/%d", 6);
//	ft_p(mr, or);

//	mr = ft_printf("number\%%d", 7);
//	printf("\n");
//	or =    printf("number\%%d", 7);
//	ft_p(mr, or);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

t_com		*ft_tcom_new(char type, char *command)
{
	t_com	*new;
	char	*str_ptr;
//	size_t 	len;

	if (!(new = (t_com*)malloc(sizeof(t_com) * 1)))
		return (NULL);
//	len = ft_strlen(command);
//	if (!(str_ptr = (char*)malloc(sizeof(char) * (len + 1))))
//		return (NULL);
//	ft_memcpy(str_ptr, command, len);
//	*(str_ptr + len) = '\0';
	str_ptr = ft_strdup(command);
	new->type = type;
	new->command = str_ptr;
	new->len = -1;
	new->next = NULL;
	return (new);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:00:32 by akalmyko          #+#    #+#             */
/*   Updated: 2016/11/30 12:01:37 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int ft_parser(const char *format, t_com **list)
{
	int 	arg;											// возвращаемое количество аргументов
	size_t 	len;											// темповая переменная для длины слова
	size_t 	start;											// темповая переменная для начала слова
	size_t 	counter;										// счетчик-переключатель для определения %
	char	sign;											// знак для записи в листы % или .
	char	*format_copy;									// копия format для отсчета от начала слова
	char	*holder;										// темповая переменная для malloc, для вырезаемого слова
	t_com	*new;											// лист t_com для сохранения переменной

	arg = 0;												// инициализация переменных
	start = 0;
	counter = 0;
	format_copy = (char*)format;
	*list = NULL;

	while (*format != '\0') 								// иду пока не достигну конца строки с аргументами
	{
		len = 0;											// устанавливаю длину слова 0
		holder = NULL;										// устанавливаю/обнуляю holder
		if (*format == '%')
		{
			counter++;
			format++;											// сдвигаю поинтер format
		}
		while (*format != '%' && *format != '\0')			// циклирую пока не дойду до знака % или не дойду до конца стринга
		{
			len++;											// увеличиваю счетчик длины слова
			format++;										// сдвигаю поинтер стринга
		}
		if (*format == '\0' && len == 0)					// проверяю на выходе, длину слова и дошел ли loop до конца
			return (arg);									// тогда возвращаю количество аргументов: 0
		holder = (char*)malloc(sizeof(char) * len + 1);		// инициализирую holder с длиной слова len + 1
		if (counter > 0)									// если первый проход, то равен нулю, впоследствии определяет % и правильно копирует из format_copy
		{
			start++; 		//len++;						// сдвигаю индекс при копировании format_copy, чтобы исключить знак %
			sign = '%';										// устанавливаю переменной sign % - для записи в лист
		}
		else
			sign = '.';										// если % не было найдено (просто стринг), то устанаваливаю знак для обычной печати
		holder = ft_strnncpy(holder, format_copy, start, len); // возможно нужно использовать memcpy
		start += len;										// добавляю к переменной start новую длину слова, для корректного вырезания в сл. цикле
		*(holder + len) = '\0';								// нуль-терминирую стринг
		new = ft_tcom_new(sign, holder);					// создаю новый лист t_com new
		if (*list == NULL)									// если это первый лист
			*list = new;									// то первым листом становится первая переменная new
		else
			ft_tcom_add(*&list, new);						// если лист уже не NULL, добавляю к нему новый лист
		free(holder);										// очищаю выделенную память для holder
		arg++;												// увеличиваю счетчик аргументов
		counter = 0;										// обнуляю тумблерную переменную counter
	}
	return (arg);											// возвращаю количество аргументов, распилинных и поделенных
}

//static void ft_get_argument(t_list *list)
//{
//
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//int			ft_parser(const char *format, t_com **list)
//{
//	int		arg;
//	size_t	len;
//	size_t	beg;
//	size_t	yn;
//	char	*copy;
//	char	*holder;
//
//
//	arg = 0;
//	beg = 0;
//	copy = (char*)format;
//	while (*copy != '\0')
//	{
//		holder = NULL;
//		ft_checker(&copy, &yn, &len, &beg);
//		if (*copy == '\0' && len == 0)
//			return (arg);
//		ft_memnncpy((holder = ft_strnew(len + 1)), format, beg, len);
//		beg += len;
//		ft_tcom_list(*&list, yn, holder);
//		arg++;
//	}
//	ft_tcom_revert(*&list);
//	return (arg);
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
		str = arg->data;
		if (ft_check_command(*str) == 0) {
			counter = counter + (int) ft_strlen(str);
			ft_putstr(str);
		} else
			counter += ft_processing(str, va_arg(ap, void *));
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

