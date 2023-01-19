# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 21:30:11 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/20 00:00:09 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = *.c

LIBFT_FILE = libft/libft.a

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	@make fclean -C libft/

fclean: clean

re:	fclean all

.PHONY: all clean fclean re