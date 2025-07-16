/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/15 16:01:59 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/MacroLibX/includes/mlx.h"
# include "../libs/MacroLibX/includes/mlx_extended.h"
# include "../libs/MacroLibX/includes/mlx_profile.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define WIDTH_WINDOW 1280
# define HEIGHT_WINDOW 800

# define FPS 120
# define FOV 70

# define LIGHT 10

# include "struct.h"

/* ************************************************************************** */
/* Initialization                                                             */
/* ************************************************************************** */

t_color					*init_color(void);
t_texture				*init_texture(void);
t_graphics				*init_graphics(void);
t_player				*init_player(void);
t_map					*init_map(void);
t_image					*init_image(void);
t_game					*init_game(void);
t_raycasting			*init_raycasting(void);
t_events				*init_events(void);
mlx_window_create_info	*init_window_info(void);

/* ************************************************************************** */
/* Cleanup                                                                    */
/* ************************************************************************** */

void					clean_color(t_color *color);
void					clean_texture(t_texture *texture, mlx_context init);
void					clean_graphics(t_graphics *graphics);
void					clean_player(t_player *player);
void					clean_map(t_map *map);
void					clean_image(t_image *image, mlx_context init);
void					clean_game(t_game *game);
void					clean_raycasting(t_raycasting *ray);
void					clean_window_info(t_game *game);
void					free_texture(t_game *game);

/* ************************************************************************** */
/* Logs                                                                       */
/* ************************************************************************** */

int						log_error(const char *message);
int						log_warn(const char *message);
int						log_info(const char	*message);
int						log_debug(const char *message);

/* ************************************************************************** */
/* Images                                                                     */
/* ************************************************************************** */

int						load_map_texture(t_texture *texture, mlx_context init);
void					load_hud_texture(t_texture *texture, mlx_context init);
int						open_image(t_image *image, mlx_context init);

/* ************************************************************************** */
/* Graphic                                                                    */
/* ************************************************************************** */

void					change_view(t_game *game, int view);
void					graphic(t_game *game);
void					raycasting(t_game *game);
void					render(void *data);
mlx_color				color(uint32_t color);
void					draw_rectangle_mlx(t_game *game, int x, int y,
							int w, int h, mlx_color color);
void					draw_wall(t_game *game, int len, int side, int i);
int						get_face(int side, int step_x, int step_y);
int						get_face_height(int side, int step_x, int step_y,
							t_texture *texture);
int						get_face_width(int side, int step_x, int step_y,
							t_texture *texture);
float					init_angle(t_game *game, int i);
void					init_calc(t_game *game, float rad);
void					init_dir(t_game *game);
float					shade_result(t_game *game, int len);
void					wall_size_texture(t_game *game, int side,
							int lineheight);
void					raycasting_floor(t_game *game);
void					raycasting_wall(t_game *game);

/* ************************************************************************** */
/* Views                                                                      */
/* ************************************************************************** */

void					render_menu(t_game *game);
void					render_game(t_game *game);
void					render_inventory(t_game *game);

/* ************************************************************************** */
/* Components    													          */
/* ************************************************************************** */

void					debug_view(t_game *game);
void					compass(t_game *game);
void					hand(t_game *game);

/* ************************************************************************** */
/* Collision                                                                  */
/* ************************************************************************** */

void					apply_position(t_player *player, t_map *map,
							float x, float y);

/* ************************************************************************** */
/* Window                                                                     */
/* ************************************************************************** */

void					create_window(t_graphics *graphics);

/* ************************************************************************** */
/* Events                                                                     */
/* ************************************************************************** */

void					subscribe_mouseup(t_graphics *graphics, t_game *game);
void					subscribe_keydown(t_graphics *graphics,
							t_events *events);
void					subscribe_keyup(t_graphics *graphics, t_events *events);
void					subscribe_window(t_graphics *graphics,
							t_events *events);
void					subscribe_events(t_game *game);

/* ************************************************************************** */
/* Maths                                                                      */
/* ************************************************************************** */

float					deg_to_rad(float angle);

/* ************************************************************************** */
/* Utils  																      */
/* ************************************************************************** */

int						min(int a, int b);
float					minf(float a, float b);
int						is_bonus(void);
void					draw_rectangle(t_graphics *graphics, int x, int y, int w, int h, mlx_color c);

/* ************************************************************************** */
/*      CHECK                                                                 */
/* ************************************************************************** */
int						check_file_map(char **argv, t_game *game);
int						check_texture(t_game *game);
int						check_ground_and_sky(t_game *game, int count);
int						check_map(t_game *game);
void					init_player_pos(t_game *game);
int						get_map(t_game *game);

/* ************************************************************************** */
/*   PLAYER                                                                   */
/* ************************************************************************** */
void					player_move_backward(t_game *game);
void					player_move_left(t_game *game);
void					player_move_right(t_game *game);
void					player_move_forward(t_game *game);
void					player_action(t_game *game);
float					player_rotate_left(t_game *game,
							float previous_rotation);
float					player_rotate_right(t_game *game,
							float previous_rotation);
void					player_exit(t_game *game);
int						find_playerx(char **map);
int						find_playery(char **map);

#endif