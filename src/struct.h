/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/21 15:50:13 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	char		*string_color;
	mlx_color	color;
}				t_color;

typedef struct s_image
{
	char		*path;
	mlx_image	img;
	int			width;
	int			height;
	mlx_color	*colors;
}				t_image;

typedef struct s_texture
{
	t_image		*north;
	t_image		*east;
	t_image		*south;
	t_image		*west;
	t_image		*sky;
	t_image		*ground;
	t_image		*battery;
	mlx_image	render;
	mlx_image	render_tmp;
	mlx_image	compass_background;
	mlx_image	compass_indicator;
	mlx_image	hands;
	mlx_image	clock_background;
	mlx_image	cub3d_logo;
	mlx_image	play_button;
	mlx_image	play_button_selected;
	mlx_image	online_button;
	mlx_image	online_button_selected;
	mlx_image	option_button;
	mlx_image	option_button_selected;
	mlx_image	exit_button;
	mlx_image	exit_button_selected;
	mlx_image	inventory_background;
	mlx_image	inventory_icon_map;
	mlx_image	inventory_icon_cases;
	mlx_image	inventory_icon_save;
	mlx_image	inventory_icon_options;
	mlx_image	inventory_icon_map_selected;
	mlx_image	inventory_icon_cases_selected;
	mlx_image	inventory_icon_save_selected;
	mlx_image	inventory_icon_options_selected;
	mlx_image	q_arrow;
	mlx_image	e_arrow;
	mlx_image	minimap_header;
	mlx_image	options_header;
	mlx_image	slider_base;
	mlx_image	slider_selected;
	mlx_image	switch_on;
	mlx_image	switch_off;
	mlx_image	switch_selected;
	mlx_image	progress_start;
	mlx_image	progress_center;
	mlx_image	progress_end;
	mlx_image	map_t;
	mlx_image	map_b;
	mlx_image	map_l;
	mlx_image	map_r;
	mlx_image	map_p;
	mlx_image	flash_panel;
	mlx_image	led_on;
	mlx_image	flash_on;
	mlx_image	flash_off;
	mlx_image	crosshair;
}				t_texture;

typedef struct s_graphics
{
	mlx_context				init;
	mlx_window				window;
	mlx_window_create_info	*info;
	int						view;
	int						frame;
	int						selection;
	struct timeval			last_time;
	double					fps;
	int						max_fps;
}				t_graphics;

typedef struct s_player
{
	int			x;
	int			y;
	float		pos_x;
	float		pos_y;
	float		rad;
	float		angle;
	int			inventory_page;
	int			selected_item;
	int			use_mouse_rotation;
	int			battery;
}				t_player;

typedef struct s_map
{
	int			fd_map;
	char		*name;
	char		**map;
	int			size;
	int			cap;
}				t_map;

typedef struct s_raycasting
{
	int			fov;
	float		cos_x;
	float		sin_y;
	float		ray_x;
	float		ray_y;
	float		raylength_x;
	float		raylength_y;
	float		rofract_x;
	float		rofract_y;
	float		perpwalldist;
	int			draw_start;
	int			draw_end;
	float		color_x;
	float		color_y;
	int			tex_y;
	int			tex_x;
	float		wall_x;
	float		tex_step;
	float		tex_pos;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	float		floorstep_x;
	float		floorstep_y;
	float		floor_x;
	float		floor_y;
	int			tx;
	int			ty;
	float		deltaangle;
	float		deg_to_rad;
	float		transform_y;
	float		transform_x;
	int			sprite_height;
	int			sprite_width;
	int			i;
}				t_raycasting;

typedef struct s_events
{
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		flashlight;
	int		rotate_left;
	int		rotate_right;
	int		exit;
	int		debug_enabled;
	int		inventory;
}	t_events;

typedef struct s_rect
{
	int	x;
	int	y;
	int	h;
	int	w;
}			t_rect;

typedef struct s_game
{
	t_texture		*texture;
	t_graphics		*graphics;
	t_map			*map;
	t_player		*player;
	t_raycasting	*ray;
	t_events		*events;
}					t_game;

#endif