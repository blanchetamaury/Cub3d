/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:20 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/23 15:56:02 by amblanch         ###   ########.fr       */
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


/*****************/
/*      CHECK    */
/*****************/
int 	check_file_map(char **argv, t_game *game);
int 	check_texture(t_game *game);

# endif