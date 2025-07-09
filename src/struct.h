/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 11:42:24 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	char		*string_color;
	mlx_color	color;
}				t_color;

typedef struct s_texture
{
	char		*north_path;
	char		*east_path;
	char		*south_path;
	char		*west_path;
	t_color		*sky;
	t_color		*ground;
}				t_texture;

typedef struct s_graphics
{
	mlx_context	init;
	mlx_window	window;
	int			frame;
}				t_graphics;

typedef struct s_player
{
	int			x;
	int			y;
	float		pos_x;
	float		pos_y;
	int			rad;
	int			angle;
}				t_player;

typedef struct s_map
{
    int         fd_map;
	char		*name;
	char		**map;
	int			size;
	int			cap;
	mlx_image	img;
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
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
}				t_raycasting;

typedef struct s_events
{
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		exit;
	int		debug_enabled;
}	t_events;

typedef struct s_game
{
	t_texture		*texture;
	t_graphics		*graphics;
	t_map			*map;
	t_player		*player;
	t_raycasting	*ray;
	t_events		*events;
} 				t_game;

#endif