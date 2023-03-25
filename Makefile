# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerhee <jerhee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 03:24:30 by jerhee          #+#    #+#              #
#    Updated: 2023/03/24 18:19:38 by jerhee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
BONUS = so_long_bonus

SRCS_M = srcs/main.c \
			srcs/parse.c \
			srcs/check_map.c \
			srcs/convert_image.c \
			srcs/print_image.c \
			srcs/event.c \
			srcs/utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			ft_printf/ft_printf.c \
			ft_printf/print_arg.c \
			ft_printf/utils.c
SRCS_B = srcs_bonus/main_bonus.c \
			srcs_bonus/parse_bonus.c \
			srcs_bonus/check_map_bonus.c \
			srcs_bonus/convert_image_bonus.c \
			srcs_bonus/print_image_bonus.c \
			srcs_bonus/event_bonus.c \
			srcs_bonus/utils_bonus.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			ft_printf/ft_printf.c \
			ft_printf/print_arg.c \
			ft_printf/utils.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS_M)
	@make -s -C libft all
	@make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit ./libft/libft.a ./mlx/libmlx.a $(OBJS_M) -o $(NAME)

$(BONUS) : $(OBJS_B)
	@make -s -C libft all
	@make -C mlx all
	gcc $(CFLAGS) -L./mlx -Imlx -framework OpenGL -framework AppKit ./libft/libft.a ./mlx/libmlx.a $(OBJS_B) -o $(BONUS)

clean :
	@make -C libft clean
	@make -C mlx clean
	@rm -f $(OBJS_M)
	@rm -f $(OBJS_B)

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re : fclean all