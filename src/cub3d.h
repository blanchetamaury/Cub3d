/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/24 14:37:27 by amblanch         ###   ########.fr       */
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

# define LIGHT_OFF 5
# define LIGHT_ON 7

# define PERCENTAGE_BATTERY  40

# define BOT_SPEED 2
# define NB_BOT 10
# define TIME_SPAWN 1

# include "struct.h"

/* ************************************************************************** */
/* Initialization                                                             */
/* ************************************************************************** */

t_color					*init_color(void);
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
void					clean_texture(t_image *texture, mlx_image *img, mlx_context init);
void					clean_graphics(t_graphics *graphics);
void					clean_player(t_player *player);
void					clean_map(t_map *map);
void					clean_image(t_image *image, mlx_context init);
void					clean_game(t_game *game);
void					clean_raycasting(t_raycasting *ray);
void					clean_window_info(t_game *game);
void					clean_event(t_events *events);
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

int						load_map_texture(t_game *game, mlx_context init);
void					load_hud_texture(mlx_image *img, mlx_context init);
int						open_image(t_image *image, mlx_context init);

/* ************************************************************************** */
/* Graphic                                                                    */
/* ************************************************************************** */

void					change_view(t_game *game, int view);
void					graphic(t_game *game);
void					raycasting(t_game *game);
void					render(void *data);
mlx_color				color(uint32_t color);
void					draw_wall(t_game *game, int len, int side, int i, t_raycasting *ray);
int						get_face(int side, int step_x, int step_y);
int						get_face_height(int side, int step_x, int step_y,
							t_image *texture);
int						get_face_width(int side, int step_x, int step_y,
							t_image *texture);
float					init_angle(t_raycasting *ray, t_player *player, int i);
void					init_calc(t_raycasting *ray, t_player *player, float rad);
void					init_dir(t_raycasting *ray);
float					shade_result(t_raycasting *ray, int len);
void					wall_size_texture(t_raycasting *ray, t_player *player, t_image *text, t_map *map, int side, int lineheight);
void					raycasting_floor(t_game *game);
void					raycasting_wall(t_game *game, int *status,
							float *z_buffer);
void					raycasting_sprite(t_game *game, int status,
							float *z_buffer);
void					init_rad_floor(t_game *game, float *dir_x,
							float *dir_y);
mlx_color				texture_shader(t_game *game, mlx_color tmp,
							float shade, float color_alpha);

/* ************************************************************************** */
/* Views                                                                      */
/* ************************************************************************** */

void					render_menu(t_game *game);
void					render_game(t_game *game);
void					render_inventory(t_game *game);
void					render_options(t_game *game);
void					render_inventory_page(t_game *game);
void					render_options_page(t_game *game);
void					render_win(t_game *game);

/* ************************************************************************** */
/* Components    													          */
/* ************************************************************************** */

void					compass(t_game *game);
void					hand(t_game *game);
void					progress(int value, int x, int y, t_game *game);
void					flashlight_panel(t_game *game);
void					debug_fps(t_game *game);
void					minimap(t_game *game, int postion_x, int postion_y);
void					switch_view(t_game *game, int is_on, int x, int y);
void					render_tab_indicator(t_game *game);

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
void					subscribe_keydown(t_game *game);
void					subscribe_keyup(t_graphics *graphics, t_events *events);
void					subscribe_window(t_graphics *graphics,
							t_events *events);
void					subscribe_events(t_game *game);

void					on_keydown_inventory(int key, t_game *game);
void					on_keydown_options(int key, t_game *game);

/* ************************************************************************** */
/* Maths                                                                      */
/* ************************************************************************** */

float					deg_to_rad(float angle);

/* ************************************************************************** */
/* Utils  																      */
/* ************************************************************************** */

int						min(int a, int b);
float					minf(float a, float b);
int						max(int a, int b);
float					maxf(float a, float b);
uint8_t					maxu(uint8_t a, uint8_t b);
int						is_bonus(void);
void					draw_circle(t_game *game, t_rect rect, uint32_t c);
double					get_time_in_seconds(void);
void					set_region_opacity(mlx_color *color, int size,
							uint8_t opacity);
void					reset_game(t_game *game);

/* ************************************************************************** */
/* Checks                                                                     */
/* ************************************************************************** */
int						check_file_map(char **argv, t_game *game);
int						check_texture(t_game *game);
int						check_ground_and_sky(t_game *game, int count);
int						check_map(t_game *game);
void					init_player_pos(t_game *game);
int						get_map(t_game *game);
int						check_door(t_game *game);

/* ************************************************************************** */
/* Player                                                                     */
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