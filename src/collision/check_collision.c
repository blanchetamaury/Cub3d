/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:54:41 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 09:45:28 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_y(float y, float x, char c, t_map *map)
{
	return (map->map[(int)(y + 0.9) - 1][(int)x] != c
		&& map->map[(int)(y + 0.1)][(int)x] != c);
}

static int	check_x(float y, float x, char c, t_map *map)
{
	return (map->map[(int)y][(int)(x + 0.9) - 1] != c
		&& map->map[(int)y][(int)(x + 0.1)] != c);
}


void	apply_position(t_player *player, t_map *map, float x, float y)
{
	if (check_y(y, x, '1', map) && check_y(y, x, 'P', map)
		&& check_y(y, x, 'C', map) && check_y(y, x, 'M', map)
		&& check_y(y, x, 'Q', map))
		player->pos_y = y;
	if (check_x(y, x, '1', map) && check_x(y, x, 'P', map)
		&& check_x(y, x, 'C', map) && check_x(y, x, 'M', map)
		&& check_y(y, x, 'Q', map))
		player->pos_x = x;
}
