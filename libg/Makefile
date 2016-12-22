NAME = libg.a

SRC = ft_new_window.c ft_put_pixel_img.c

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
