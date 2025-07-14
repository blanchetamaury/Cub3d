/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:52:25 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 10:59:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_move_left(t_game *game)
{
	float	x;
	float	y;
	float	angle_rad;

	if (game->events->move_left)
	{
		angle_rad = deg_to_rad(game->player->angle - 90);
		x = game->player->pos_x + (cos(angle_rad) * 0.1);
		y = game->player->pos_y + (sin(angle_rad) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
}
