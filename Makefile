# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: ccavalca <ccavalca@student.42sp.org.br>      +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 0026/01/24 00:28:58 by ccavalca            #+#    #+#             #
#   Updated: 2026/01/24 01:12:37 by ccavalca           ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

# ============================================================================
# COMPILER & FLAGS
# ============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS		+=	-I./inc -I./libft/inc $(MLX42_INC)
MLX42_INC = -I$(MLX42_DIR)/include
MLX42_LIB = -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lGL -lpthread -lm
MLX42_A = $(MLX42_DIR)/build/libmlx42.a
DEBUG_FLAGS	=	-g3 -DDEBUG
CFLAGS_OPT	=	-O2 -funroll-loops
LDFLAGS = $(MLX42_LIB)

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/
LIBFT_DIR	=	libft/
MLX42_DIR = MLX42
BONUS_DIR	=	src_bonus/

# ============================================================================
# FILES (MANDATORY, COMMON, BONUS)
# ============================================================================

COMMON_SRC = \
	src/parsing/map_parsing.c \
	src/parsing/map_utils.c \
	src/parsing/map_validation.c \
	src/parsing/path_validation.c \
	src/utils/cleanup.c \
	src/utils/errors.c \
	src/stubs.c

MANDATORY_SRC = \
    src/main.c \
    src/game/moves.c \
    src/parsing/color_utils.c \
    src/parsing/textures_parsing.c

BONUS_SRC = \
    src_bonus/alguma_func_bonus.c

MANDATORY_OBJ_FILES = $(MANDATORY_SRC:.c=.o)
COMMON_OBJ_FILES = $(COMMON_SRC:.c=.o)
BONUS_OBJ_FILES = $(BONUS_SRC:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(MANDATORY_OBJ_FILES) $(COMMON_OBJ_FILES))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(BONUS_OBJ_FILES) $(COMMON_OBJ_FILES))

TARGET = cub3D

# ============================================================================
# LIBRARY
# ============================================================================

LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

# ============================================================================
# RULES
# ============================================================================


.PHONY: all clean fclean re bonus debug help



all: $(MLX42_A) $(TARGET)



$(TARGET): $(OBJS) $(LIBFT) $(MLX42_A)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT_FLAGS) $(LDFLAGS)
	@echo "✓ $(TARGET) compiled successfully"
$(MLX42_A):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build > /dev/null 2>&1 || true
	@$(MAKE) -C $(MLX42_DIR)/build
	@echo "✓ MLX42 compiled"

bonus:
	@$(CC) $(CFLAGS) -o cub3D_bonus $(OBJS_BONUS) $(LIBFT_FLAGS)
	@echo "✓ cub3D_bonus compiled successfully (bonus)"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓ Compiling $<"

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@echo "✓ Libft compiled"

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all
	@echo "✓ Debug build complete"

release: CFLAGS += $(CFLAGS_OPT)
release: clean all
	@echo "✓ Release build complete"

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "✓ Object files cleaned"

fclean: clean
	@rm -f $(TARGET)
	@make -C $(LIBFT_DIR) fclean
	@echo "✓ All files cleaned"

re: fclean all

# ============================================================================
# ADDITIONAL RULES
# ============================================================================

run: all
	@./$(TARGET)

valgrind: debug
	@valgrind --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(TARGET)

norm:
	@norminette $(SRC_DIR) $(INC_DIR)
	@echo "✓ Norminette check done"

help:
	@echo "Available targets:"
	@echo "  make all      - Build the project"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove all generated files"
	@echo "  make re       - Rebuild everything"
	@echo "  make debug    - Build with debug symbols"
	@echo "  make release  - Build optimized release"
	@echo "  make run      - Build and run"
	@echo "  make valgrind - Run with valgrind"
	@echo "  make norm     - Check norminette"
	@echo "  make bonus    - Build the project with bonuses"
