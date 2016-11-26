cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address")

set(SOURCE_FILES
		temp/main.c
		ft_printf.c
		ft_putstr.c
		ft_putchar.c
		ft_putnbr.c
		ft_strlen.c
		ft_isdigit.c
		ft_printf/ft_is_helper.c
		ft_printf/ft_printf_helpers.c
		ft_printf/ft_printf_parser.c
#		ft_atoi_base.c
		)
add_executable(ft_printf ${SOURCE_FILES})