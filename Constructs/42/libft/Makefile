# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdorner <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 10:43:57 by jdorner           #+#    #+#              #
#    Updated: 2018/09/25 15:01:21 by jdorner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES = ft_isalnum.c\
	   	ft_isprint.c\
	   	ft_memchr.c\
	   	ft_memmove.c\
	   	ft_putendl.c\
		ft_putstr.c\
	   	ft_strclr.c\
	   	ft_strdup.c\
	   	ft_strjoin.c\
	   	ft_strmapi.c\
		ft_strnequ.c\
	   	ft_strstr.c\
	   	ft_toupper.c\
	   	ft_isalpha.c\
	   	ft_itoa.c\
		ft_memcmp.c\
	   	ft_memset.c\
	   	ft_putendl_fd.c\
	   	ft_putstr_fd.c\
		ft_putlst.c\
	   	ft_strcmp.c\
		ft_strequ.c\
	   	ft_strlcat.c\
	   	ft_strncat.c\
		ft_strnew.c\
	   	ft_strsub.c\
		ft_atoi.c\
	   	ft_isascii.c\
		ft_memalloc.c\
	   	ft_memcpy.c\
		ft_putchar.c\
		ft_putnbr.c\
	   	ft_strcat.c\
	   	ft_strcpy.c\
	   	ft_striter.c\
	   	ft_strlen.c\
		ft_strncmp.c\
	   	ft_strnstr.c\
	   	ft_strtrim.c\
		ft_bzero.c\
	   	ft_isdigit.c\
	   	ft_memccpy.c\
	   	ft_memdel.c\
	   	ft_putchar_fd.c\
		ft_putnbr_fd.c\
	   	ft_strchr.c\
	   	ft_strdel.c\
	   	ft_striteri.c\
	   	ft_strmap.c\
		ft_strncpy.c\
	   	ft_strrchr.c\
	   	ft_tolower.c\
	   	ft_lstnew.c\
		ft_lstadd.c\
		ft_lstcount.c\
	   	ft_lstdel.c\
	   	ft_lstdelone.c\
	   	ft_lstmap.c\
	   	ft_lstiter.c\
		ft_lstfree.c\
		ft_lstrev.c\
	   	ft_strsplit.c\
		ft_abs.c\
		ft_max.c\
		ft_min.c\
		ft_rm_char.c\
		ft_lst_ignorecomments.c\
		ft_wrdcount.c\

OBJECT = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECT) 
	ar -rc $(NAME) $(OBJECT)

$(OBJECT): %.o: %.c
	$(CC) $(CFLAGS) $*.c -o $@

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
