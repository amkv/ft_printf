cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fsanitize=address")

set(SOURCE_FILES
		libft/ft_putstr.c
		libft/ft_putchar.c
		libft/ft_putnbr.c
		libft/ft_strlen.c
		libft/ft_isdigit.c
		libft/ft_memcpy.c
		libft/ft_strncpy.c
		libft/ft_strdup.c
		libft/ft_strnew.c
		libft/ft_bzero.c
		libft/ft_toupper.c
		libft/ft_itoa.c
		libft/ft_strjoin.c
		libft/ft_atoi.c
		libft/ft_isspace.c
		libft/ft_strcmp.c
		libft/ft_strchr_qt.c

		temp/main.c
		ft_printf/ft_printf.c
		ft_printf/ft_printf_parser.c
		ft_printf/ft_printf_is.c
#		ft_printf/ft_printf_flags.c
		ft_printf/ft_printf_patterns_1.c
		ft_printf/ft_printf_patterns_2.c
		ft_printf/ft_printf_lists.c
		ft_printf/ft_printf_helpers.c
		ft_printf/ft_printf_switch.c
		ft_printf/ft_printf_do.c
		ft_printf/ft_printf_do_psc.c
		ft_printf/ft_printf_do_d_1.c
		ft_printf/ft_printf_do_d_2.c
		ft_printf/ft_printf_do_oux_1.c
		ft_printf/ft_printf_do_oux_2.c
		ft_printf/ft_printf_pre_print.c
		ft_printf/ft_printf_switch_length.c
		ft_printf/ft_printf_wide_char.c

		ft_extra_functions/ft_strnncpy.c
		ft_extra_functions/ft_memnncpy.c
		ft_extra_functions/ft_itoa_base.c
		ft_extra_functions/ft_numlen.c
		ft_extra_functions/ft_strdel_begn.c
		ft_extra_functions/ft_ftoa.c
		ft_extra_functions/ft_pow.c
		ft_extra_functions/ft_strdupn.c
		ft_extra_functions/ft_itoa_base_uintmax.c
		)
add_executable(ft_printf ${SOURCE_FILES})