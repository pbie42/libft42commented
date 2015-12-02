# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbie <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 18:33:46 by pbie              #+#    #+#              #
#    Updated: 2015/11/30 19:49:47 by pbie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi \
	  ft_bzero \
	  ft_isalnum \
	  ft_isalpha \
	  ft_isascii \
	  ft_isdigit \
	  ft_isprint \
	  ft_itoa \
	  ft_memalloc \
	  ft_memccpy \
	  ft_memchr \
	  ft_memcmp \
	  ft_memcpy \
	  ft_memdel \
	  ft_memmove \
	  ft_memset \
	  ft_putchar \
	  ft_putchar_fd \
	  ft_putendl \
	  ft_putendl_fd \
	  ft_putnbr \
	  ft_putnbr_fd \
	  ft_putstr \
	  ft_putstr_fd \
	  ft_strcat \
	  ft_strchr \
	  ft_strclr \
	  ft_strcmp \
	  ft_strcpy \
	  ft_strdel \
	  ft_strdup \
	  ft_strequ \
	  ft_striter \
	  ft_striteri \
	  ft_strjoin \
	  ft_strlcat \
	  ft_strlen \
	  ft_strmap \
	  ft_strmapi \
	  ft_strncat \
	  ft_strncmp \
	  ft_strncpy \
	  ft_strnequ \
	  ft_strnew \
	  ft_strnstr \
	  ft_strrchr \
	  ft_strsplit \
	  ft_strstr \
	  ft_strsub \
	  ft_strtrim \
	  ft_tolower \
	  ft_toupper

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
