# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalevesq <jalevesq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 13:47:04 by jalevesq          #+#    #+#              #
#    Updated: 2022/11/04 07:01:07 by jalevesq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memset.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strncmp.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_calloc.c \
	ft_memmove.c \
	ft_atoi.c	\
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_itoa.c 

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
	

CC=gcc
CFLAGS=-Wall -Werror -Wextra
OBJS=$(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs  $(NAME) $(OBJS)

clean:
	@/bin/rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean

	@/bin/rm -f $(NAME)

re: fclean all
	@echo "Re-compilation terminé."

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
