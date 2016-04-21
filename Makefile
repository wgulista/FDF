.PHONY: all, clean, fclean, re

NAME = fdf
LIBFT = libft.a
MINILIBX = minilibx.a
SRC_NAME = 	main.c
OBJ_PATH = obj
SRC_PATH = srcs

CFLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LIBX = -lm -L libft/ -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
		@gcc $(LIBX) $(OBJ) -o $(NAME)
		@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(LIBFT):
		@make -C ./libft/

$(MINILIBX):
		@make -C ./minilibx/

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
		@mkdir -p $(OBJ_PATH)
		@gcc $(CFLAGS) -o $@ -c $^
		@echo "\033[33mLinking" [ $< ] "\033[0m"

clean:
		@rm -fv $(OBJ)
		@rm -Rf $(OBJ_PATH)
		@make clean -C ./libft/
		@make clean -C ./minilibx/
		@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
		@rm -fv $(NAME)
		@make fclean -C ./libft/
		@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all
