# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 21:30:11 by ylabrahm          #+#    #+#              #
#    Updated: 2023/02/02 22:54:45 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_bfs_utils_2.c \
		so_checkmap_2.c \
		so_checkmap_3.c \
		so_bfs_utils.c \
		so_checkmap.c \
		so_utils_2.c \
		so_utils.c \
		so_long.c \
		so_bfs.c

LIBFT_FILE = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) $(OBJS) libft/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	@make fclean -C libft/

fclean: clean

re:	fclean all

.PHONY: all clean fclean re