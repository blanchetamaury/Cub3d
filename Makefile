NAME = cub3d

CC = cc
CFLAGS = -Werror -Wall -Wextra -g -Isrc/

GNL = libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c

LIBS = libs/libft/libft.a $(GNL)

CHECKS = src/checks/check_map.c \
			src/checks/check_texture.c

SRC = src/main.c $(CHECKS)
OBJDIR = .obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)


clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all