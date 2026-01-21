##
## EPITECH PROJECT, [YEAR]
## [PROJECT_NAME]
## File description:
## Makefile for [PROJECT_NAME]
##

# ============================================================================
# COMPILER & FLAGS
# ============================================================================

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS		+=	-I./inc -I./libft/inc
DEBUG_FLAGS	=	-g3 -DDEBUG
CFLAGS_OPT	=	-O2 -funroll-loops

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/
LIBFT_DIR	=	libft/

# ============================================================================
# FILES
# ============================================================================

SRC_FILES	=	main.c \
				utils.c \
				processing.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

TARGET		=	Cub3D

# ============================================================================
# LIBRARY
# ============================================================================

LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

# ============================================================================
# RULES
# ============================================================================

.PHONY: all clean fclean re debug help

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBFT_FLAGS)
	@echo "✓ $(TARGET) compiled successfully"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
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
