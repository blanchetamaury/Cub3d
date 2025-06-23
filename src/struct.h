/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/23 15:29:06 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3d.h"

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_texture
{
	char		*north_path;
	char		*east_path;
	char		*south_path;
	char		*west_path;
	t_color		sky;
	t_color		ground;
}				t_texture;

typedef struct s_graphics
{
	///    
}				t_graphics;

typedef struct s_map
{
	///
    int         fd_map;
	char		*name;
}				t_map;

typedef struct s_game
{
	t_texture	*texture;
	t_graphics	*graphics;
	t_map		*map;
} 				t_game;

#endif