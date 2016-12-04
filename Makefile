# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:50:24 by akalmyko          #+#    #+#              #
#    Updated: 2016/12/03 21:08:22 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
RM = /bin/rm -rfv
CFILES = ft_atoi.c  ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c
CFILES += ft_isdigit.c  ft_isprint.c  ft_isspace.c  ft_itoa.c  ft_lstadd.c
CFILES += ft_lstdel.c  ft_lstdelone.c  ft_lstiter.c  ft_lstmap.c  ft_lstnew.c
CFILES += ft_memalloc.c  ft_memccpy.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c
CFILES += ft_memdel.c  ft_memmove.c  ft_memset.c  ft_nextchar.c  ft_prvschar.c
CFILES += ft_ptrlen.c  ft_ptrtoend.c  ft_putchar.c  ft_putchar_fd.c  ft_putendl.c
CFILES += ft_putendl_fd.c  ft_putnbr.c  ft_putnbr_fd.c  ft_putstr.c  ft_putstr_fd.c
CFILES += ft_skipchr.c  ft_skipspace_beg.c  ft_skipspace_end.c  ft_skiptochr.c
CFILES += ft_strcat.c  ft_strchr.c  ft_strchr_qt.c  ft_strchrto_end.c  ft_strclr.c
CFILES += ft_strcmp.c  ft_strcpy.c  ft_strdel.c  ft_strdup.c  ft_strequ.c
CFILES += ft_striter.c  ft_striteri.c  ft_strjoin.c  ft_strlcat.c  ft_strlen.c
CFILES += ft_strmap.c  ft_strmapi.c  ft_strncat.c  ft_strncmp.c  ft_strncpy.c
CFILES += ft_strnequ.c  ft_strnew.c  ft_strnstr.c  ft_strrchr.c  ft_strsplit.c
CFILES += ft_strstr.c  ft_strsub.c  ft_strtrim.c  ft_tolower.c  ft_toupper.c
CFILES += ft_get_next_line.c
CFILES += ft_printf.c

FTCFILES += ft_printf/ft_memnncpy.c ft_printf/ft_printf_helpers.c 
FTCFILES += ft_printf/ft_printf_is.c ft_printf/ft_printf_lists.c 
FTCFILES += ft_printf/ft_printf_parser.c ft_printf/ft_strnncpy.c
FTCFILES += ftprintf/ft_printf_switch.c ft_printf/ft_printf_do.c

OFILES = $(CFILES:.c=.o)
OFILES += ft_memnncpy.o ft_printf_helpers.o ft_printf_is.o ft_printf_lists.o
OFILES += ft_printf_parser.o ft_strnncpy.o ft_printf_switch.o ft_printf_do.o

all: $(NAME)

$(NAME):
	@echo compiling...
	@$(CC) $(FLAGS) $(CFILES) $(FTCFILES)
	@ar rc $(NAME) $(OFILES)
	@ranlib $(NAME)
	@echo $(NAME) created

clean: 
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all
