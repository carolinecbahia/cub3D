# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 17:03:32 by ccavalca          #+#    #+#              #
#    Updated: 2025/08/14 21:18:21 by ccavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

FT_PRINTF_SRC = ft_printf.c \
			ft_printf_utils.c \
			specifiers_chars.c \
			specifiers_nbrs.c
				
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)
OBJ = $(FT_PRINTF_OBJ)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re