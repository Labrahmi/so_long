# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 21:30:11 by ylabrahm          #+#    #+#              #
#    Updated: 2023/01/10 19:18:52 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRCS = 	so_long.c \
		so_checkmap.c \
		so_utils.c \
		so_bfs_map.c \
		libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_calloc.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_itoa.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_split.c \
		libft/ft_strchr.c \
		libft/ft_strdup.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlcpy.c \
		libft/ft_strlen.c \
		libft/ft_strmapi.c \
		libft/ft_strncmp.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strtrim.c \
		libft/ft_substr.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c \
		libft/get_next_line.c \
		libft/ft_printf.c \
		libft/sources/ft_print_char.c \
		libft/sources/ft_print_hexp.c \
		libft/sources/ft_print_str_.c \
		libft/sources/ft_print_hexl.c \
		libft/sources/ft_print_int_.c \
		libft/sources/ft_print_uint.c 

SRC_B =	libft/ft_lstadd_back_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

CC = cc

RM = rm -f

# CFLAGS = -Wall -Wextra -Werror 

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
	$(RM) $(NAME)
	$(RM) *.out
	clear

re:			fclean all
	gcc so_long.a 
	clear
	./a.out maps/map-3.ber

bonus:		$(OBJS_B) $(OBJS)
	ar rcs $(NAME) $(OBJS_B) $(OBJS)
