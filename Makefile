END				= \033[0m
YELLOW			= \033[33m
RED				= \033[31m
HIGH_RED		= \033[91m
GREEN			= \033[32m
BLUE			= \033[34m

NAME			= cub3D
CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror -fcommon
RM				= rm -rf
LIBFT_DIR		= libft
MLX_LINUX_DIR	= mlx_linux
MLX_DIR			= mlx
INCLUDE			= includes/
SRC_DIR			= src
OBJ_DIR			= objs
LIBFT			= $(LIBFT_DIR)/libft.a
MLX				= $(MLX_DIR)/libmlx.a
MLX_LINUX		= $(MLX_LINUX_DIR)/libmlx_Linux.a
LIBS			= $(LIBFT)
SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin)
	LIBS += $(MLX)
	LINKER_MAC = -framework OpenGL -framework AppKit
	MINILIBX = mlx
else ifeq ($(detected_OS),Linux)
	LIBS += $(MLX_LINUX)
	LINKER_LINUX += -L$(MLX_LINUX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_LINUX_DIR) -lXext -lX11 -lm -lz
	LINUX_OBJ_FLAGS = -I/usr/include -I$(MLX_LINUX_DIR)
	MINILIBX = mlx_linux
endif


all: $(NAME)

$(NAME): $(LIBS) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LINKER_MAC) -I $(INCLUDE) $(OBJS) $(LIBS) $(LINKER_LINUX) -o $@
	@echo "$(GREEN)[+] $(NAME) compiled$(END)"



$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(BLUE)[+] $@ folder created$(END)"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)[+] libft compiled$(END)"

$(MLX_LINUX):
	@chmod +x $(MLX_LINUX_DIR)/configure
	@make -s -C $(MLX_LINUX_DIR) 2> /dev/null 1> /dev/null
	@echo "$(GREEN)[+] mlx_linux compiled$(END)"

$(MLX):
	@make -s -C $(MLX_DIR) 2> /dev/null
	@echo "$(GREEN)[+] mlx compiled$(END)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) $(LINUX_OBJ_FLAGS) -c $< -o $@
	@echo "$(BLUE)[+] $@ compiled$(END)"



clean:
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(YELLOW)[+] libft cleaned$(END)"
	@make -s -C $(MINILIBX) clean 1> /dev/null
	@echo "$(YELLOW)[+] $(MINILIBX) cleaned$(END)"
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)[+] $(NAME) cleaned$(END)"

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(YELLOW)[+] libft fcleaned$(END)"
	@$(RM) $(NAME)
	@echo "$(YELLOW)[+] $(NAME) fcleaned$(END)"

re: fclean $(NAME)



bonus: all

norm:
	clear
	@norminette $(LIBFT_DIR) $(INCLUDE) $(SRC_DIR)

grep_leaks:
	make leaks_invalid | grep "total leaked bytes"


test: all
	clear
	@./$(NAME) maps/default.cub

run: test
rrun: fclean test

var: all
	clear
	@valgrind --leak-check=full ./$(NAME) maps/default.cub
val: var

leaks: all
	clear
	@leaks --atExit -- ./$(NAME) maps/default.cub

copy:
	@$(RM) ../$(NAME)_backup
	@mkdir -p ../$(NAME)_backup
	@cp -r * ../$(NAME)_backup
	@echo "$(GREEN)[+] Copied project$(END)"
backup: copy
up: copy

sanitize:	re
			@$(CC) $(DEBUG_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -lm -o $(NAME)
			$(info [Making with fsanitize=address ...])

tar: clean_mac fclean
	@tar -cf ../$(NAME).tar .
	@echo "$(GREEN)[+] Made tar$(END)"

clean_mac:
	@find . -name "._*" -delete
	@find . -name ".DS_Store" -delete
	@echo "$(YELLOW)[+] Nasty MAC files cleaned$(END)"

clean_cache:
	@rm -rf ~/Library/Caches && rm -rf ~/Library/Application\ Support/Code/Cache && rm -rf ~/Library/Application\ Support/Code/User/workspaceStorage

.PHONY: all clean fclean re
