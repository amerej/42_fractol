NAME = libg.a

SRC = ft_init_env.c ft_draw_pixel_img \

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -L./minilibx_osx -L./libg

LDLIBS = -lmlx -framework OpenGL -framework AppKit -lg -lm

.PHONY: all, clean, fclean, re

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs  $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
