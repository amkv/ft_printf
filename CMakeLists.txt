cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_CXX_FLAGS -Wall -Wextra -Werror -I. -fsanitize=address)

set(SOURCE_FILES
		ft_printf.c
		temp/main.c
		)
add_executable(ft_printf ${SOURCE_FILES})