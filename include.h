/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/23 10:58:04 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_extended.h"
# include "MacroLibX/includes/mlx_profile.h"

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
	char		*name;
}				t_map;

typedef struct s_game
{
	t_texture	*texture;
	t_graphics	*graphics;
	t_map		*map;
} 				t_game;

# endif