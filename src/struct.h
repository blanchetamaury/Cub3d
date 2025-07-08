/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/08 16:33:46 by amblanch         ###   ########.fr       */
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
}				t_graphics;

typedef struct s_player
{
	int			x;
	int			y;
	float			pos_x;
	float			pos_y;
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
}				t_map;

typedef struct s_game
{
	t_texture	*texture;
	t_graphics	*graphics;
	t_map		*map;
	t_player	*player;
	int			key[300];
} 				t_game;

#endif