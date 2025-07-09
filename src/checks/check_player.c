/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:34:32 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 11:35:36 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_pos(t_game *game)
{
	game->player->x = find_playerx(game->map->map);
	game->player->y = find_playery(game->map->map);
	if (game->map->map[game->player->y][game->player->x] == 'N')
		game->player->angle = 0;
	if (game->map->map[game->player->y][game->player->x] == 'E')
		game->player->angle = 90;
	if (game->map->map[game->player->y][game->player->x] == 'S')
		game->player->angle = 180;
	if (game->map->map[game->player->y][game->player->x] == 'W')
		game->player->angle = 270;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->pos_y = game->player->y + 0.5;
	game->player->pos_x = game->player->x + 0.5;
}