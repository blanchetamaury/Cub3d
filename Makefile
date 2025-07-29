NAME = cub3d

CC = cc
CFLAGS = -Werror -Wall -Wextra -Ofast -g -Isrc/

GNL = libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c

LIBS = libs/libft/libft.a $(GNL) libs/MacroLibX/libmlx.so -lSDL2 -lm

SRC_INIT =			src/initialization/get_player_pos.c \
					src/initialization/init_color.c \
					src/initialization/init_graphics.c \
					src/initialization/init_player.c \
					src/initialization/init_map.c \
					src/initialization/init_game.c \
					src/initialization/init_image.c \
					src/initialization/init_raycasting.c \
					src/initialization/init_window_info.c \
					src/initialization/init_event.c

SRC_CHECKS =		src/checks/check_map.c \
					src/checks/check_texture.c \
					src/checks/check_map_valid.c \
					src/checks/check_player.c \
					src/checks/check_door.c \
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
					src/cleanup/clean_image.c \
					src/cleanup/clean_raycasting.c \
					src/cleanup/clean_window_info.c \
					src/cleanup/clean_event.c

SRC_IMAGES =		src/images/open_image.c \
					src/images/load_map_texture.c \
					src/images/load_animated_texture.c \
					src/images/load_hud_texture.c

SRC_GRAPHICS =		src/raycasting/graphics.c \
					src/raycasting/raycasting.c \
					src/raycasting/render.c \
					src/raycasting/init_calc.c \
					src/raycasting/get_face.c \
					src/raycasting/draw_texture.c \
					src/raycasting/raycasting_wall.c \
					src/raycasting/raycasting_floor.c \
					src/raycasting/raycasting_sprite.c \
					src/raycasting/raycasting_ghost.c \
					src/raycasting/raycasting_door.c \
					src/raycasting/shader.c \
					src/raycasting/calc_sprite.c \
					src/raycasting/calc_door.c

SRC_EVENTS =		src/event/subscribe_events.c \
					src/event/subscribe_keydown.c \
					src/event/subscribe_keyup.c \
					src/event/subscribe_mouseup.c \
					src/event/subscribe_window.c \
					src/event/pages/inventory.c \
					src/event/pages/options.c

SRC_COLLISION =		src/collision/check_collision.c

SRC_ENEMY =			src/enemy/spawn.c \
					src/enemy/manager.c

SRC_VIEWS =			src/views/render_game.c \
					src/views/render_menu.c \
					src/views/render_options.c \
					src/views/render_win.c \
					src/views/render_lose.c \
					src/views/render_inventory.c \
					src/views/render_inventory_page.c \
					src/views/render_options_page.c

SRC_COMPONENTS =	src/components/compass.c \
					src/components/hand.c \
					src/components/progress.c\
					src/components/debug_fps.c \
					src/components/flashlight_panel.c \
					src/components/minimap.c \
					src/components/switch.c \

SRC_WINDOW =		src/window/create_window.c

SRC_MATH =			src/math/deg_to_rad.c

SRC_UTILS =			src/utils/min.c \
					src/utils/max.c \
					src/utils/is_bonus.c \
					src/utils/color.c \
					src/utils/time.c \
					src/utils/reset_game.c \
					src/utils/animation.c \

SRC_PLAYER =		src/player/player_move_backward.c \
					src/player/player_move_forward.c \
					src/player/player_move_left.c \
					src/player/player_move_right.c \
					src/player/player_action.c \
					src/player/player_exit.c \
					src/player/player_rotate_left.c \
					src/player/player_rotate_right.c

SRC		=	src/main.c \
			${SRC_INIT} \
			${SRC_CHECKS} \
			${SRC_LOGS} \
			${SRC_IMAGES} \
			${SRC_GRAPHICS} \
			${SRC_WINDOW} \
			${SRC_EVENTS} \
			${SRC_VIEWS} \
			${SRC_COMPONENTS} \
			${SRC_COLLISION} \
			${SRC_ENEMY} \
			${SRC_MATH} \
			${SRC_UTILS} \
			${SRC_CLEANUP} \
			$(SRC_PLAYER)

OBJDIR = .obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

bonus: CFLAGS += -DBONUS
bonus: $(LIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)

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

rebonus: fclean bonus