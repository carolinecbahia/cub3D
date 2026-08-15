# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ccavalca <ccavalca@student.42sp.org.br>      +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0025/07/12 19:09:24 by cavalca             #+#    #+#             #
#   Updated: 2026/04/14 23:10:39 by ccavalca           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #


# ============================================================================
# COMPILER & FLAGS
# ============================================================================

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./inc -Ift_printf/inc
DEBUG_FLAGS	= -g3 -DDEBUG
CFLAGS_OPT	= -O2 -funroll-loops

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR	= src/
INC_DIR	= inc/
OBJ_DIR	= obj/


# ============================================================================
# ARQUIVOS FONTE (LISTAGEM EXPLÍCITA)
# ============================================================================

MANDATORY_SRC = \
	src/mandatory/ft_atoi.c \
	src/mandatory/ft_bzero.c \
	src/mandatory/ft_calloc.c \
	src/mandatory/ft_isalnum.c \
	src/mandatory/ft_isalpha.c \
	src/mandatory/ft_isascii.c \
	src/mandatory/ft_isdigit.c \
	src/mandatory/ft_isprint.c \
	src/mandatory/ft_itoa.c \
	src/mandatory/ft_memchr.c \
	src/mandatory/ft_memcmp.c \
	src/mandatory/ft_memcpy.c \
	src/mandatory/ft_memmove.c \
	src/mandatory/ft_memset.c \
	src/mandatory/ft_putchar_fd.c \
	src/mandatory/ft_putendl_fd.c \
	src/mandatory/ft_putnbr_fd.c \
	src/mandatory/ft_putstr_fd.c \
	src/mandatory/ft_split.c \
	src/mandatory/ft_strchr.c \
	src/mandatory/ft_strdup.c \
	src/mandatory/ft_striteri.c \
	src/mandatory/ft_strjoin.c \
	src/mandatory/ft_strlcat.c \
	src/mandatory/ft_strlcpy.c \
	src/mandatory/ft_strlen.c \
	src/mandatory/ft_strmapi.c \
	src/mandatory/ft_strncmp.c \
	src/mandatory/ft_strnstr.c \
	src/mandatory/ft_strrchr.c \
	src/mandatory/ft_strtrim.c \
	src/mandatory/ft_substr.c \
	src/mandatory/ft_tolower.c \
	src/mandatory/ft_toupper.c

ADDITIONAL_SRC = \
	src/addtional/ft_atoi_safe.c \
	src/addtional/ft_atol.c \
	src/addtional/ft_free_matrix.c \
	src/addtional/ft_isspace.c \
	src/addtional/ft_itoa_base.c \
	src/addtional/ft_lst_get_node.c \
	src/addtional/ft_lst_remove_if.c \
	src/addtional/ft_matrix_len.c \
	src/addtional/ft_printf_fd.c \
	src/addtional/ft_putstr_color_fd.c \
	src/addtional/ft_strcmp.c \
	src/addtional/ft_strjoin_free.c \
	src/addtional/ft_strndup.c


BONUS_SRC = \
	src/bonus/ft_lstadd_back.c \
	src/bonus/ft_lstadd_front.c \
	src/bonus/ft_lstclear.c \
	src/bonus/ft_lstdelone.c \
	src/bonus/ft_lstiter.c \
	src/bonus/ft_lstlast.c \
	src/bonus/ft_lstmap.c \
	src/bonus/ft_lstnew.c \
	src/bonus/ft_lstsize.c

PRINTF_SRC = \
	ft_printf/src/specifiers_chars.c \
	ft_printf/src/specifiers_nbrs.c \
	ft_printf/src/bonus/ft_printf.c \
	ft_printf/src/bonus/ft_printf_utils.c

GNL_SRC = \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

SRC_FILES = $(MANDATORY_SRC) $(ADDITIONAL_SRC) $(BONUS_SRC) $(PRINTF_SRC) $(GNL_SRC)

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(OBJ_FILES)))

TARGET = libft.a

# ============================================================================
# RULES
# ============================================================================

.PHONY: all clean fclean re debug release help


all: $(TARGET)

$(TARGET): $(OBJS)
	@ar rcs $(TARGET) $(OBJS)
	@echo "✓ $(TARGET) compilada com sucesso"


$(OBJ_DIR)%.o: src/mandatory/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/addtional/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/bonus/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: ft_printf/src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: ft_printf/src/bonus/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: gnl/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all
	@echo "✓ Build debug completo"

release: CFLAGS += $(CFLAGS_OPT)
release: clean all
	@echo "✓ Build release completo"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "✓ Objetos removidos"
fclean: clean
	@rm -f $(TARGET)
	@echo "✓ Todos os arquivos removidos"
re: fclean all

.PHONY:	all clean fclean re

# ============================================================================
# ADDITIONAL RULES
# ============================================================================

help:
	@echo "Targets disponíveis:"
	@echo "  make all      - Compila a libft"
	@echo "  make clean    - Remove objetos"
	@echo "  make fclean   - Remove todos os arquivos gerados"
	@echo "  make re       - Recompila tudo"
	@echo "  make debug    - Build com símbolos de debug"
	@echo "  make release  - Build otimizado"
	@echo "  make help     - Exibe esta ajuda"