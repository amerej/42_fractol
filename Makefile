
NAME = fractol

SRC_PATH = srcs

SRC_NAME = main.c events.c fractals.c check_user_input.c

OBJ_PATH = objs

INC_PATH = includes

OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc

#CFLAGS = -Werror -Wextra -Wall

CPPFLAGS = -I$(INC_PATH)

LDFLAGS = -L./libft -L./minilibx_osx -L./libg

LDLIBS = -lft -lmlx -framework OpenGL -framework AppKit -lg -lm

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./libg
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C ./libft clean
	make -C ./libg clean

fclean: clean
	rm -fv $(NAME)
	make -C ./libft fclean
	make -C ./libg fclean

re:	fclean all
