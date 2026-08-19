# ============================================================================
# cub3D - Makefile
# ============================================================================

# ============================================================================
# PROJECT
# ============================================================================

NAME		= cub3D
BONUS_NAME	= cub3D_bonus
CC			= cc

# ============================================================================
# DIRECTORIES
# ============================================================================

SRC_DIR			= src/
INC_DIR			= inc/
BONUS_INC_DIR	= inc_bonus/
OBJ_DIR			= obj/
LIBFT_DIR		= libft/
MLX42_DIR		= MLX42

# ============================================================================
# FLAGS AND LIBRARIES
# ============================================================================

CFLAGS		= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS		+= -MMD -MP
CFLAGS		+= -I$(INC_DIR)
CFLAGS		+= -I$(BONUS_INC_DIR)
CFLAGS		+= -I$(LIBFT_DIR)/inc
CFLAGS		+= -I$(LIBFT_DIR)/ft_printf/inc
CFLAGS		+= -I$(MLX42_DIR)/include

DEBUG_FLAGS	= -g3 -DDEBUG
OPT_FLAGS	= -O2 -funroll-loops

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

MLX42_A		= $(MLX42_DIR)/build/libmlx42.a
MLX42_LIB	= -L$(MLX42_DIR)/build -lmlx42
MLX42_LIB	+= -lglfw -ldl -lGL -lpthread -lm

LDFLAGS		= $(LIBFT_FLAGS) $(MLX42_LIB)

MAKEFLAGS	+= --no-print-directory
.DEFAULT_GOAL := all

# ============================================================================
# SOURCES - MANDATORY
# ============================================================================

CORE_SRC = \
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
	src/parsing/cub_parsing.c \
	src/parsing/grid_utils.c \
	src/parsing/map_parsing.c \
	src/parsing/map_utils.c \
	src/parsing/map_validation.c \
	src/parsing/parsing_utils.c \
	src/parsing/textures_parsing.c \
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

# ============================================================================
# SOURCES - BONUS
# ============================================================================

BONUS_SRC = \
	src_bonus/main_bonus.c \
	src_bonus/hooks/mouse_hook.c

# ============================================================================
# OBJECTS AND DEPENDENCIES
# ============================================================================

MANDATORY_SRC_NO_MAIN	= $(filter-out src/main.c, $(MANDATORY_SRC))
CORE_OBJS				= $(CORE_SRC:.c=.o)
MANDATORY_OBJS			= $(MANDATORY_SRC:.c=.o)
MAND_OBJS_NO_MAIN		= $(MANDATORY_SRC_NO_MAIN:.c=.o)
BONUS_OBJS				= $(BONUS_SRC:.c=.o)

OBJS		= $(addprefix $(OBJ_DIR), $(CORE_OBJS) $(MANDATORY_OBJS))
OBJS_BONUS	= $(addprefix $(OBJ_DIR), $(CORE_OBJS) \
	$(MAND_OBJS_NO_MAIN) $(BONUS_OBJS))

DEPS		= $(OBJS:.o=.d)
DEPS_BONUS	= $(OBJS_BONUS:.o=.d)

# ============================================================================
# 42 MANDATORY RULES
# ============================================================================

.PHONY: all clean fclean re bonus banner

all: banner $(NAME)

$(NAME): $(MLX42_A) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@printf "\033[32m✓\033[0m $(NAME) compiled successfully\n"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[34m➜\033[0m compiling $<\n"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX42_A):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@$(MAKE) -C $(MLX42_DIR)/build

clean: banner
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: banner clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: banner fclean all

# ============================================================================
# 42 BONUS RULE
# ============================================================================

bonus: banner $(BONUS_NAME)

$(BONUS_NAME): $(MLX42_A) $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LDFLAGS)
	@printf "\033[32m✓\033[0m $(BONUS_NAME) compiled successfully\n"

# ============================================================================
# ADDITIONAL DEVELOPMENT TOOLS
# Everything below this point is optional and evaluator-independent.
# ============================================================================

# ----------------------------------------------------------------------------
# Runtime defaults
# ----------------------------------------------------------------------------

MAP		?= maps/valid/valid_basic.cub
ARGS	?=

INVALID_MAPS = \
	maps/invalid/bad_extension.txt \
	maps/invalid/bad_rgb.cub \
	maps/invalid/corner_leak.cub \
	maps/invalid/double_player.cub \
	maps/invalid/duplicate_color.cub \
	maps/invalid/duplicate_texture.cub \
	maps/invalid/empty.cub \
	maps/invalid/info_after_map.cub \
	maps/invalid/internal_space_leak.cub \
	maps/invalid/invalid_char.cub \
	maps/invalid/invalid_identifier.cub \
	maps/invalid/missing_color.cub \
	maps/invalid/missing_texture.cub \
	maps/invalid/newline_in_map.cub \
	maps/invalid/no_player.cub \
	maps/invalid/open_east.cub \
	maps/invalid/open_north.cub \
	maps/invalid/open_south.cub \
	maps/invalid/open_wall.cub \
	maps/invalid/open_west.cub \
	maps/invalid/rgb_empty_component.cub \
	maps/invalid/rgb_extra_component.cub \
	maps/invalid/rgb_letters.cub \
	maps/invalid/rgb_missing_component.cub \
	maps/invalid/rgb_overflow.cub \
	maps/invalid/space_leak.cub \
	maps/invalid/tab_in_map.cub

# ----------------------------------------------------------------------------
# Colors
# ----------------------------------------------------------------------------

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

# ----------------------------------------------------------------------------
# Build modes
# ----------------------------------------------------------------------------

.PHONY: banner debug release

debug: banner
	@$(MAKE) clean
	@$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)" all

release: banner CFLAGS += $(OPT_FLAGS)
release: banner clean all

# ----------------------------------------------------------------------------
# Run
# ----------------------------------------------------------------------------

.PHONY: banner run run_bonus

run: banner all
	@./$(NAME) $(MAP) $(ARGS)

run_bonus: banner bonus
	@./$(BONUS_NAME) $(MAP) $(ARGS)

# ----------------------------------------------------------------------------
# Valgrind
# ----------------------------------------------------------------------------

VAL_CMD = valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	--track-fds=yes

.PHONY: banner valgrind valgrind_bonus

valgrind: banner debug
	@$(VAL_CMD) ./$(NAME) $(MAP) $(ARGS)

valgrind_bonus: banner debug bonus
	@$(VAL_CMD) ./$(BONUS_NAME) $(MAP) $(ARGS)

# ----------------------------------------------------------------------------
# GDB
# ----------------------------------------------------------------------------

define GDB_HELP

$(CYAN)GDB Quick Reference$(RESET)
  make gdb MAP=maps/valid/valid_basic.cub
                                Compila e inicia no GDB
  run                           Executa o programa
  break main                    Breakpoint na main
  break <funcao>                Breakpoint em uma funcao
  next                          Proxima linha, sem entrar na funcao
  step                          Proxima linha, entrando na funcao
  continue                      Continua a execucao
  print <variavel>              Mostra uma variavel
  display <variavel>            Mostra a variavel em cada parada
  backtrace                     Mostra a pilha de chamadas
  info locals                   Mostra as variaveis locais
  info breakpoints              Lista os breakpoints
  delete <numero>               Remove um breakpoint
  quit                          Sai do GDB

$(YELLOW)Dicas cub3D:$(RESET)
  print game->player
  print game->map
  print ray
  print *game
  backtrace

endef
export GDB_HELP

.PHONY: banner gdb gdb_bonus gdb_help

gdb: banner debug
	@gdb --args ./$(NAME) $(MAP) $(ARGS)

gdb_bonus: banner debug bonus
	@gdb --args ./$(BONUS_NAME) $(MAP) $(ARGS)

gdb_help:
	@printf '%s\n' "$$GDB_HELP"

# ----------------------------------------------------------------------------
# Invalid map tests
# ----------------------------------------------------------------------------

.PHONY: banner maps_test

maps_test: all
	@passed=0; failed=0; \
	for file in $(INVALID_MAPS); do \
		printf "\n$(MAGENTA)$(ARROW) Testing $$file$(RESET)\n"; \
		timeout 2s ./$(NAME) "$$file" > /tmp/cub3d_map_test.log 2>&1; \
		result=$$?; \
		if [ -s /tmp/cub3d_map_test.log ]; then \
			printf "$(DIM)Program output:$(RESET)\n"; \
			sed 's/^/  /' /tmp/cub3d_map_test.log; \
		else \
			printf "$(YELLOW)No error message produced$(RESET)\n"; \
		fi; \
		if [ $$result -eq 124 ]; then \
			printf "$(RED)✗ FAIL: map opened or timed out$(RESET)\n"; \
			failed=$$((failed + 1)); \
		elif [ $$result -eq 0 ]; then \
			printf "$(RED)✗ FAIL: invalid map was accepted$(RESET)\n"; \
			failed=$$((failed + 1)); \
		else \
			printf "$(GREEN)$(OK) PASS: map rejected$(RESET)\n"; \
			passed=$$((passed + 1)); \
		fi; \
	done; \
	rm -f /tmp/cub3d_map_test.log; \
	printf "\n$(BOLD)Invalid maps: $$passed passed, $$failed failed$(RESET)\n"; \
	test $$failed -eq 0

# ----------------------------------------------------------------------------
# Norminette
# ----------------------------------------------------------------------------

.PHONY: banner norm

norm:
	@norminette $(SRC_DIR) $(INC_DIR)

# ----------------------------------------------------------------------------
# Help and banner
# ----------------------------------------------------------------------------

.PHONY: help banner

help:
	@printf "$(BOLD)42 rules$(RESET)\n"
	@printf "  make              build mandatory\n"
	@printf "  make bonus        build bonus\n"
	@printf "  make clean        remove objects\n"
	@printf "  make fclean       remove objects and binaries\n"
	@printf "  make re           rebuild mandatory\n"
	@printf "\n$(BOLD)Additional rules$(RESET)\n"
	@printf "  make run [MAP=path]          run mandatory\n"
	@printf "  make run_bonus [MAP=path]    run bonus\n"
	@printf "  make maps_test               test invalid maps\n"
	@printf "  make norm                    run Norminette\n"
	@printf "  make debug                   build with debug symbols\n"
	@printf "  make release                 optimized build\n"
	@printf "  make valgrind [MAP=path]     run Valgrind\n"
	@printf "  make valgrind_bonus          run bonus with Valgrind\n"
	@printf "  make gdb [MAP=path]          run GDB\n"
	@printf "  make gdb_bonus               run bonus in GDB\n"
	@printf "  make gdb_help                show GDB reference\n"

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
	@printf "                [ cub3D ]                 \n"
	@printf "$(RESET)\n"

# ============================================================================
# AUTO DEPENDENCIES
# ============================================================================

-include $(DEPS)
-include $(DEPS_BONUS)
