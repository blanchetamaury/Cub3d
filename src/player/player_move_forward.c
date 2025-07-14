/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_forward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:51:01 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 10:56:40 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_move_forward(t_game *game)
{
	float	x;
	float	y;

	if (game->events->move_forward)
	{
		x = game->player->pos_x + (cos(deg_to_rad(game->player->angle)) * 0.1);
		y = game->player->pos_y + (sin(deg_to_rad(game->player->angle)) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
}
