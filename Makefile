NAME = cub3d

CC = cc
CFLAGS = -Werror -Wall -Wextra -g

LIB = libft/libft.a

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all