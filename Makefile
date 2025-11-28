NAME = so_long

# Source files
SRCS = so_long.c input_validator.c map_parser.c helper.c helper_two.c \
			 map_validator.c game_initializor.c game_render.c player_movement.c \

OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = 
RM = rm -f

# Colors for pretty output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Libft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
LIBFT_INC = -I $(LIBFT_DIR)

# FT_Printf
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB  = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf
FT_PRINTF_INC  = -I $(FT_PRINTF_DIR)

# MiniLibX
MLX_DIR = mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MLX_INC = -I$(MLX_DIR) -I.

all: $(NAME)

$(LIBFT_LIB):
	@echo "Building Libft"
	@make -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	@echo "Building FT_Printf..."
	@make -C $(FT_PRINTF_DIR)

$(MLX_LIB):
	@echo "Building MiniLibX..."
	@make -C $(MLX_DIR)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(FT_PRINTF_INC) $(MLX_INC) -O3 -c $< -o $@

$(NAME): $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_LIB) $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(FT_PRINTF_DIR)
	@make -C $(MLX_DIR)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
