cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address")

set(SOURCE_FILES
		ft_putstr.c
		ft_putchar.c
		ft_putnbr.c
		ft_strlen.c
		ft_isdigit.c
		ft_memcpy.c
		ft_strncpy.c
		ft_strdup.c
		ft_strnew.c
		ft_bzero.c
		ft_toupper.c
		ft_itoa.c
		ft_strjoin.c
		ft_atoi.c
		ft_isspace.c

		temp/main.c
		ft_printf.c
		ft_printf/ft_printf_is.c
		ft_printf/ft_printf_helpers.c
		ft_printf/ft_printf_parser.c
		ft_printf/ft_printf_lists.c
		ft_printf/ft_printf_switch.c
		ft_printf/ft_printf_do.c
		ft_printf/ft_printf_patterns.c
		ft_printf/ft_printf_pre_print.c
		ft_printf/ft_strnncpy.c
		ft_printf/ft_memnncpy.c
		ft_printf/ft_itoa_base.c
		ft_printf/ft_numlen.c
		ft_printf/ft_strdel_begn.c
		ft_printf/ft_ftoa.c
		ft_printf/ft_pow.c
		)
add_executable(ft_printf ${SOURCE_FILES})