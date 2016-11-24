# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:50:24 by akalmyko          #+#    #+#              #
#    Updated: 2016/11/23 17:09:21 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror -c
RM = /bin/rm -rfv
PREFIX = libft/
#OLIBFT = $(shell cat $(PREFIX).ofiles_list)
OLST = ofiles_list
CFILES = ft_printf.c
#OLIBFT = $(shell cat libft/ofiles_list | tr ' ' '\n' | sed 's/^/libft\//' | tr '\n' ' ')
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(PREFIX)
	@$(shell cat $(PREFIX)$(OLST))
	@#echo compiling... ft_printf
	@#$(CC) $(FLAGS) $(CFILES)
	@#echo "combining libft & ft_printf"
	@#ar rc $(NAME) $(OFILES) $(shell cat $(PREFIX)$(OLST))
	@#ranlib $(NAME)
	@#$(NAME) created

clean: 
	@make clean -C $(PREFIX)
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_printf_*.o files deleted 

fclean: clean
	@$(RM) $(PREFIX)libft.a | wc -l | tr '\n' ' ' && echo libft.a deleted
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all
