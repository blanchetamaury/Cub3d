/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:52:02 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 10:58:48 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_move_right(t_game *game)
{
	float	x;
	float	y;
	float	angle_rad;

	if (game->events->move_right)
	{
		angle_rad = deg_to_rad(game->player->angle + 90);
		x = game->player->pos_x + (cos(angle_rad) * 0.1);
		y = game->player->pos_y + (sin(angle_rad) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
}
