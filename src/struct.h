/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 10:41:30 by amblanch         ###   ########.fr       */
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
}				t_graphics;

typedef struct s_player
{
	int			x;
	int			y;
	float		pos_x;
	float		pos_y;
	float		rad;
	float		angle;
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