/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:54:41 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 13:57:20 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	apply_position(t_player *player, t_map *map, float x, float y)
{
	if (map->map[(int)(y + 0.9) - 1][(int)x] == '1')
		return;
	if (map->map[(int)(y + 0.1)][(int)x] == '1')
		return;
	if (map->map[(int)y][(int)(x + 0.9) - 1] == '1')
		return;
	if (map->map[(int)y][(int)(x + 0.1)] == '1')
		return;
	player->pos_x = x;
	player->pos_y = y;
}
