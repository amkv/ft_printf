# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:50:24 by akalmyko          #+#    #+#              #
#    Updated: 2016/12/20 17:34:45 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
RM = /bin/rm -rfv
L = libft/
E = ft_extra_functions/
P = ft_printf/

LC = $(L)ft_atoi.c
LC += $(L)ft_bzero.c
LC += $(L)ft_isalnum.c
LC += $(L)ft_isalpha.c
LC += $(L)ft_isascii.c
LC += $(L)ft_isdigit.c
LC += $(L)ft_isprint.c
LC += $(L)ft_isspace.c
LC += $(L)ft_itoa.c
LC += $(L)ft_lstadd.c
LC += $(L)ft_lstdel.c
LC += $(L)ft_lstdelone.c
LC += $(L)ft_lstiter.c
LC += $(L)ft_lstmap.c
LC += $(L)ft_lstnew.c
LC += $(L)ft_memalloc.c
LC += $(L)ft_memccpy.c
LC += $(L)ft_memchr.c
LC += $(L)ft_memcmp.c
LC += $(L)ft_memcpy.c
LC += $(L)ft_memdel.c
LC += $(L)ft_memmove.c
LC += $(L)ft_memset.c
LC += $(L)ft_nextchar.c
LC += $(L)ft_prvschar.c
LC += $(L)ft_ptrlen.c
LC += $(L)ft_ptrtoend.c
LC += $(L)ft_putchar.c
LC += $(L)ft_putchar_fd.c
LC += $(L)ft_putendl.c
LC += $(L)ft_putendl_fd.c
LC += $(L)ft_putnbr.c
LC += $(L)ft_putnbr_fd.c
LC += $(L)ft_putstr.c
LC += $(L)ft_putstr_fd.c
LC += $(L)ft_skipchr.c
LC += $(L)ft_skipspace_beg.c
LC += $(L)ft_skipspace_end.c
LC += $(L)ft_skiptochr.c
LC += $(L)ft_strcat.c
LC += $(L)ft_strchr.c
LC += $(L)ft_strchr_qt.c
LC += $(L)ft_strchrto_end.c
LC += $(L)ft_strclr.c
LC += $(L)ft_strcmp.c
LC += $(L)ft_strcpy.c
LC += $(L)ft_strdel.c
LC += $(L)ft_strdup.c
LC += $(L)ft_strequ.c
LC += $(L)ft_striter.c
LC += $(L)ft_striteri.c
LC += $(L)ft_strjoin.c
LC += $(L)ft_strlcat.c
LC += $(L)ft_strlen.c
LC += $(L)ft_strmap.c
LC += $(L)ft_strmapi.c
LC += $(L)ft_strncat.c
LC += $(L)ft_strncmp.c
LC += $(L)ft_strncpy.c
LC += $(L)ft_strnequ.c
LC += $(L)ft_strnew.c
LC += $(L)ft_strnstr.c
LC += $(L)ft_strrchr.c
LC += $(L)ft_strsplit.c
LC += $(L)ft_strstr.c
LC += $(L)ft_strsub.c
LC += $(L)ft_strtrim.c
LC += $(L)ft_tolower.c
LC += $(L)ft_toupper.c
LC += $(L)ft_get_next_line.c

PC = $(P)ft_printf.c
PC += $(P)ft_printf_helpers.c
PC += $(P)ft_printf_is.c
PC += $(P)ft_printf_lists.c
PC += $(P)ft_printf_parser.c
PC += $(P)ft_printf_switch.c
PC += $(P)ft_printf_switch_length.c
PC += $(P)ft_printf_do.c
PC += $(P)ft_printf_do_s.c
PC += $(P)ft_printf_do_p.c
PC += $(P)ft_printf_do_d_1.c
PC += $(P)ft_printf_do_d_2.c
PC += $(P)ft_printf_patterns_1.c
PC += $(P)ft_printf_patterns_2.c
PC += $(P)ft_printf_pre_print.c
PC += $(P)ft_printf_flags.c

EC = $(E)ft_memnncpy.c
EC += $(E)ft_strnncpy.c
EC += $(E)ft_itoa_base.c
EC += $(E)ft_strdel_begn.c
EC += $(E)ft_numlen.c
EC += $(E)ft_pow.c
EC += $(E)ft_ftoa.c
EC += $(E)ft_strdupn.c
EC += $(E)ft_itoa_base_uintmax.c

OF += ft_atoi.o
OF += ft_bzero.o
OF += ft_isalnum.o
OF += ft_isalpha.o
OF += ft_isascii.o
OF += ft_isdigit.o
OF += ft_isprint.o
OF += ft_isspace.o
OF += ft_itoa.o
OF += ft_lstadd.o
OF += ft_lstdel.o
OF += ft_lstdelone.o
OF += ft_lstiter.o
OF += ft_lstmap.o
OF += ft_lstnew.o
OF += ft_memalloc.o
OF += ft_memccpy.o
OF += ft_memchr.o
OF += ft_memcmp.o
OF += ft_memcpy.o
OF += ft_memdel.o
OF += ft_memmove.o
OF += ft_memset.o
OF += ft_nextchar.o
OF += ft_prvschar.o
OF += ft_ptrlen.o
OF += ft_ptrtoend.o
OF += ft_putchar.o
OF += ft_putchar_fd.o
OF += ft_putendl.o
OF += ft_putendl_fd.o
OF += ft_putnbr.o
OF += ft_putnbr_fd.o
OF += ft_putstr.o
OF += ft_putstr_fd.o
OF += ft_skipchr.o
OF += ft_skipspace_beg.o
OF += ft_skipspace_end.o
OF += ft_skiptochr.o
OF += ft_strcat.o
OF += ft_strchr.o
OF += ft_strchr_qt.o
OF += ft_strchrto_end.o
OF += ft_strclr.o
OF += ft_strcmp.o
OF += ft_strcpy.o
OF += ft_strdel.o
OF += ft_strdup.o
OF += ft_strequ.o
OF += ft_striter.o
OF += ft_striteri.o
OF += ft_strjoin.o
OF += ft_strlcat.o
OF += ft_strlen.o
OF += ft_strmap.o
OF += ft_strmapi.o
OF += ft_strncat.o
OF += ft_strncmp.o
OF += ft_strncpy.o
OF += ft_strnequ.o
OF += ft_strnew.o
OF += ft_strnstr.o
OF += ft_strrchr.o
OF += ft_strsplit.o
OF += ft_strstr.o
OF += ft_strsub.o
OF += ft_strtrim.o
OF += ft_tolower.o
OF += ft_toupper.o
OF += ft_get_next_line.o

OF += ft_printf.o
OF += ft_printf_helpers.o
OF += ft_printf_is.o
OF += ft_printf_lists.o
OF += ft_printf_parser.o
OF += ft_printf_switch.o
OF += ft_printf_do.o
OF += ft_printf_do_s.o
OF += ft_printf_do_p.o
OF += ft_printf_do_d_1.o
OF += ft_printf_do_d_2.o
OF += ft_strdel_begn.o
OF += ft_printf_patterns_1.o
OF += ft_printf_patterns_2.o
OF += ft_printf_pre_print.o
OF += ft_printf_flags.o
OF += ft_printf_switch_length.o

OF += ft_memnncpy.o
OF += ft_strnncpy.o
OF += ft_itoa_base.o
OF += ft_numlen.o
OF += ft_pow.o
OF += ft_ftoa.o
OF += ft_strdel_begn.o
OF += ft_strdupn.o
OF += ft_itoa_base_uintmax.o

all: $(NAME)

$(NAME):
	@echo compiling...
	@$(CC) $(FLAGS) $(LC) $(EC) $(PC)
	@ar rc $(NAME) $(OF)
	@ranlib $(NAME)
	@echo $(NAME) created

clean: 
	@$(RM) $(OF) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all
