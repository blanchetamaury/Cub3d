/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:18:43 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/26 12:58:38 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	reset_game(t_game *game)
{
	int	y;
	int	x;

	game->player->pos_x = game->player->base_pos_x;
	game->player->pos_y = game->player->base_pos_y;
	game->player->angle = game->player->base_angle;
	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'O' || game->map->map[y][x] == 'C'
				|| game->map->map[y][x] == 'M')
				game->map->map[y][x] = 'P';
			x++;
		}
		y++;
	}
	game->player->battery = 200 * 2;
	y = 0;
	while (y < game->ray->count_bot)
		game->bot[y++].life = 0;
}
