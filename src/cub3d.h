/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/01 15:27:45 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/MacroLibX/includes/mlx.h"
# include "../libs/MacroLibX/includes/mlx_extended.h"
# include "../libs/MacroLibX/includes/mlx_profile.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "struct.h"


/* ************************************************************************** */
/* Initialization                                                             */
/* ************************************************************************** */

t_color			*init_color(void);
t_texture		*init_texture(void);
t_graphics		*init_graphics(void);
t_player		*init_player(void);
t_map			*init_map(void);
t_game			*init_game(void);

/* ************************************************************************** */
/* cleanup                                                                    */
/* ************************************************************************** */

void			clean_color(t_color *color);
void			clean_texture(t_texture *texture);
void			clean_graphics(t_graphics *graphics);
void			clean_player(t_player *player);
void			clean_map(t_map *map);
void			clean_game(t_game *game);

/*****************/
/*      CHECK    */
/*****************/
int 	check_file_map(char **argv, t_game *game);
int 	check_texture(t_game *game);
int	    check_ground_and_sky(t_game *game, int count);
int     check_map(t_game *game);
int     get_map(t_game *game);

/*****************/
/*    CLEANUP    */
/*****************/
void	free_texture(t_game *game);

/*****************/
/*    INIT       */
/*****************/
int	    find_playerx(char **map);
int 	find_playery(char **map);

# endif