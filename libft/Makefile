# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabrahm <ylabrahm@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 21:30:11 by ylabrahm          #+#    #+#              #
#    Updated: 2023/02/02 22:19:47 by ylabrahm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf/ft_printf.c \
		ft_printf/sources/ft_print_char.c \
		ft_printf/sources/ft_print_hexl.c \
		ft_printf/sources/ft_print_int_.c \
		ft_printf/sources/ft_print_str_.c \
		ft_printf/sources/ft_print_uint.c \
		ft_printf/sources/ft_print_hexp.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c 

SRC_B =	ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I.

NAME = libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

bonus:		$(OBJS_B) $(OBJS)
	ar rcs $(NAME) $(OBJS_B) $(OBJS)
