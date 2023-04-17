NAME = so_long
SRC = main.c
OBJ = $(.c=.o)
LIBFT = ./libft
CC = 			@cc
CFLAGS = 		-Wall -Wextra -Werror -g
MLX_FLAGS = 	-L$(LIBMLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
LIBMLX_DIR =		./mlx_linux
MLX_INCLUDE = 	-Imlx_linux

(NAME):	$(SRC)
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(@) 
#-fsanitize=address

clean:
			@rm -f
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR) clean

fclean:		clean
			@rm -f $(NAME)
			@$(MAKE) --no-print-directory -C $(LIBMLX_DIR) clean

re:			fclean all

.PHONY: all clean fclean re
