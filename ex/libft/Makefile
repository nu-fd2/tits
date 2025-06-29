# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 17:00:38 by oel-mado          #+#    #+#              #
#    Updated: 2025/06/25 17:58:01 by mdakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c\
	ft_bzero.c\
	my_calloc.c\
	my_isalnum.c\
	my_isalpha.c\
	ft_isascii.c\
	my_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	my_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	my_split.c\
	ft_strchr.c\
	my_strdup.c\
	my_strndup.c\
	ft_striteri.c\
	my_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	my_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	my_strcmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	my_substr.c\
	ft_tolower.c\
	ft_toupper.c
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
