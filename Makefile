NAME = so_long

# Source files
SRCS = so_long.c input_validator.c map_parser.c helper.c helper_two.c \
			map_validator.c game_initializor.c game_render.c player_movement.c \
			libft_helper.c ft_itoa.c ft_split.c

OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Colors for pretty output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# MiniLibX
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_INC = -I$(MLX_DIR) -I.

all: $(NAME)

$(MLX_LIB):
	@echo "Building MiniLibX..."
	@make -C $(MLX_DIR)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(MLX_INC) -O3 -c $< -o $@

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS)  $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@make -C $(MLX_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
