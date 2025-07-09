NAME = cub3d

CC = cc
CFLAGS = -Werror -Wall -Wextra -g -Isrc/

GNL = libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c

LIBS = libs/libft/libft.a $(GNL) libs/MacroLibX/libmlx.so -lSDL2 -lm

SRC_INIT =			src/initialization/get_player_pos.c \
					src/initialization/init_color.c \
					src/initialization/init_texture.c \
					src/initialization/init_graphics.c \
					src/initialization/init_player.c \
					src/initialization/init_map.c \
					src/initialization/init_game.c \
					src/initialization/init_raycasting.c \
					src/initialization/init_window_info.c \
					src/initialization/init_event.c

SRC_CHECKS =		src/checks/check_map.c \
					src/checks/check_texture.c \
					src/checks/check_color.c \
					src/checks/check_map_valid.c \
					src/checks/check_player.c \
					src/checks/create_map.c

SRC_LOGS =			src/logs/log_error.c \
					src/logs/log_info.c \
					src/logs/log_debug.c \
					src/logs/log_warn.c \

SRC_CLEANUP =		src/cleanup/clean_game.c \
					src/cleanup/clean_map.c \
					src/cleanup/clean_texture.c \
					src/cleanup/clean_graphics.c \
					src/cleanup/clean_player.c \
					src/cleanup/clean_color.c \
					src/cleanup/clean_raycasting.c

SRC_GRAPHICS =		src/graphics/graphics.c \
					src/graphics/raycasting.c \
					src/graphics/render.c

SRC_EVENTS =		src/event/subscribe_events.c \
					src/event/subscribe_keydown.c \
					src/event/subscribe_keyup.c \
					src/event/subscribe_window.c

SRC_COLLISION =		src/collision/check_collision.c

SRC_VIEWS =			src/views/render_game.c

SRC_COMPONENTS =	src/components/debug_view.c

SRC_WINDOW =		src/window/create_window.c

SRC_MATH =			src/math/deg_to_rad.c

SRC		=	src/main.c \
			${SRC_INIT} \
			${SRC_CHECKS} \
			${SRC_LOGS} \
			${SRC_GRAPHICS} \
			${SRC_WINDOW} \
			${SRC_EVENTS} \
			${SRC_VIEWS} \
			${SRC_COMPONENTS} \
			${SRC_COLLISION} \
			${SRC_MATH} \
			${SRC_CLEANUP}

OBJDIR = .obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBS):
	make -C libs/libft
	make -C libs/MacroLibX

clean:
	make -C libs/libft clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all