# ============================================================================
# cub3D - Makefile
# ============================================================================

# ============================================================================
# PROJECT
# ============================================================================

NAME		= cub3D
BONUS_NAME	= cub3D_bonus
CC			= gcc

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR			= src/
INC_DIR			= inc/
BONUS_INC_DIR	= inc_bonus/
OBJ_DIR			= obj/
DEP_DIR			= dep/

LIBFT_DIR	= libft/
MLX42_DIR	= MLX42

# ============================================================================
# RUNTIME DEFAULTS
# ============================================================================

MAP			?= maps/valid/random_valid_1.cub
ARGS		?= 

# ============================================================================
# FLAGS
# ============================================================================

CFLAGS		= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS		+= -MMD -MP
CFLAGS		+= -I$(INC_DIR)
CFLAGS		+= -I$(BONUS_INC_DIR)
CFLAGS		+= -I$(LIBFT_DIR)/inc
CFLAGS		+= -I$(LIBFT_DIR)/ft_printf/inc
CFLAGS		+= -I$(MLX42_DIR)/include
CFLAGS		+= -lm

DEBUG_FLAGS	= -g3 -DDEBUG
OPT_FLAGS	= -O2 -funroll-loops

MLX42_A		= $(MLX42_DIR)/build/libmlx42.a
MLX42_LIB	= -L$(MLX42_DIR)/build -lmlx42 -lglfw -ldl -lGL -lpthread -lm

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

LDFLAGS		= $(LIBFT_FLAGS) $(MLX42_LIB)

MAKEFLAGS	+= --no-print-directory
.DEFAULT_GOAL := all

# ============================================================================
# COLORS
# ============================================================================

RESET		= \033[0m
BOLD		= \033[1m
DIM			= \033[2m

RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
MAGENTA		= \033[35m
CYAN		= \033[36m

OK			= ✓
ARROW		= ➜

# ============================================================================
# SOURCES
# ============================================================================

CORE_SRC = \
	src/parsing/map_utils.c \
	src/parsing/grid_utils.c \
	src/parsing/map_building.c \
	src/parsing/map_parsing.c \
	src/parsing/parsing_utils.c \
	src/utils/cleanup.c \
	src/utils/errors.c \
	src/utils/math_utils.c \
	src/utils/strings.c \
	src/utils/debug.c \
	src/game/destroy_game.c \
	src/game/init_player.c \
	src/hooks/close_hook.c

MANDATORY_SRC = \
	src/main.c \
	src/parsing/color_parsing.c \
	src/parsing/textures_parsing.c \
	src/parsing/map_validation.c \
	src/parsing/path_validation.c \
	src/parsing/validation_utils.c \
	src/game/init_game.c \
	src/game/load_textures.c \
	src/rendering/render_frame.c \
	src/rendering/render_background.c \
	src/rendering/draw_line.c \
	src/rendering/put_pixel.c \
	src/rendering/texture_sampling.c \
	src/raycasting/raycast.c \
	src/raycasting/ray_init.c \
	src/raycasting/ray_dda.c \
	src/raycasting/ray_distance.c \
	src/raycasting/ray_texture.c \
	src/hooks/key_hook.c \
	src/hooks/movement.c \
	src/hooks/rotation.c \
	src/hooks/update_hook.c \
	src/hooks/collision.c

BONUS_SRC = \
	src_bonus/main_bonus.c \
	src_bonus/hooks/mouse_hook.c

# ============================================================================
# OBJECTS
# ============================================================================

MANDATORY_SRC_NO_MAIN = $(filter-out src/main.c, $(MANDATORY_SRC))
CORE_OBJS		= $(CORE_SRC:.c=.o)
MANDATORY_OBJS	= $(MANDATORY_SRC:.c=.o)
BONUS_OBJS		= $(BONUS_SRC:.c=.o)
MAND_OBJS_NO_MAIN	= $(MANDATORY_SRC_NO_MAIN:.c=.o)

OBJS		= $(addprefix $(OBJ_DIR), $(CORE_OBJS) $(MANDATORY_OBJS))

OBJS_BONUS	= $(addprefix $(OBJ_DIR), $(CORE_OBJS) $(MAND_OBJS_NO_MAIN) $(BONUS_OBJS))

DEPS		= $(OBJS:.o=.d)
DEPS_BONUS	= $(OBJS_BONUS:.o=.d)

# ============================================================================
# RULES
# ============================================================================

.PHONY: all bonus clean fclean re debug release \
run run_bonus valgrind valgrind_bonus \
maps_test norm help banner

all: banner $(MLX42_A) $(NAME)

bonus: banner $(MLX42_A) $(BONUS_NAME)

# ============================================================================
# BINARIES
# ============================================================================

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@printf "$(GREEN)$(OK)$(RESET) $(BOLD)$(NAME)$(RESET) compiled successfully\n"

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LDFLAGS)
	@printf "$(GREEN)$(OK)$(RESET) $(BOLD)$(BONUS_NAME)$(RESET) compiled successfully\n"

# ============================================================================
# LIBRARIES
# ============================================================================

$(LIBFT):
	@printf "$(CYAN)$(ARROW) Building libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@printf "$(GREEN)$(OK)$(RESET) libft ready\n"

$(MLX42_A):
	@printf "$(CYAN)$(ARROW) Building MLX42...$(RESET)\n"
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build > /dev/null 2>&1 || true
	@$(MAKE) -C $(MLX42_DIR)/build
	@printf "$(GREEN)$(OK)$(RESET) MLX42 ready\n"

# ============================================================================
# COMPILATION
# ============================================================================

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BLUE)$(ARROW)$(RESET) compiling $(DIM)$<$(RESET)\n"

# ============================================================================
# BUILD MODES
# ============================================================================

debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean all

release: CFLAGS += $(OPT_FLAGS)
release: clean all

# ============================================================================
# RUN
# ============================================================================

run: all
	@./$(NAME) $(MAP) $(ARGS)

run_bonus: bonus
	@./$(BONUS_NAME) $(MAP) $(ARGS)

# ============================================================================
# VALGRIND
# ============================================================================

VAL_CMD = valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes

valgrind: debug
	@$(VAL_CMD) ./$(NAME) $(MAP) $(ARGS)

valgrind_bonus: debug bonus
	@$(VAL_CMD) ./$(BONUS_NAME) $(MAP) $(ARGS)

# ============================================================================
# MAP TEST LOOP
# ============================================================================

maps_test: all
	@for file in maps/tests/*.cub; do \
		printf "$(MAGENTA)$(ARROW) Testing $$file$(RESET)\n"; \
		./$(NAME) $$file; \
	done

# ============================================================================
# CLEAN
# ============================================================================

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# ============================================================================
# TOOLS
# ============================================================================

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

help:
	@echo "make              build mandatory"
	@echo "make bonus        build bonus"
	@echo "make run          run with MAP="
	@echo "make run MAP=maps/a.cub"
	@echo "make run_bonus"
	@echo "make valgrind"
	@echo "make valgrind_bonus"
	@echo "make maps_test"
	@echo "make debug"
	@echo "make release"
	@echo "make clean / fclean / re"

banner:
	@printf "\n$(BOLD)$(CYAN)"
	@printf " ██████╗██╗   ██╗██████╗ ██████╗ ██████╗ \n"
	@printf "██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗\n"
	@printf "██║     ██║   ██║██████╔╝ █████╔╝██║  ██║\n"
	@printf "██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║\n"
	@printf "╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝\n"
	@printf " ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ \n"
	@printf "$(MAGENTA)"
	@printf "══════════════════════════════════════════\n"
	@printf "      ░░  Raycasting Engine • MLX42 ░░   \n"
	@printf "══════════════════════════════════════════\n"
	@printf "$(GREEN)"
	@printf "                [ cub3D ]                \n"
	@printf "$(RESET)\n"

# ============================================================================
# AUTO DEPENDENCIES
# ============================================================================

-include $(DEPS)
-include $(DEPS_BONUS)
