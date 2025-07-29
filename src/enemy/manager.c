/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:57:32 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/29 16:59:08 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	del_ghost(t_game *game)
{
	int	i;
	int	tmp_x;
	int	tmp_y;

	i = 0;
	while (i < game->ray->count_bot)
	{
		tmp_x = game->ray->map_x - game->bot[i].pos_x;
		tmp_y = game->ray->map_y - game->bot[i].pos_y;
		if (tmp_x < 0)
			tmp_x *= -1;
		if (tmp_y < 0)
			tmp_y *= -1;
		if (tmp_x < 1 && tmp_y < 1)
			game->bot[i].life = 0;
		i++;
	}
}

static void	enemy_die(t_game *game, int bot_index)
{
	game->player->battery -= 20 * 5;
	game->bot[bot_index].pos_x = -1;
	game->bot[bot_index].pos_y = -1;
	if (game->player->battery <= 0)
		change_view(game, 5);
}

void	enemy_manager(t_game *game)
{
	int		i;
	float	dx;
	float	dy;
	float	dist;

	spawn_enemy(game);
	i = 0;
	while (game->ray->count_bot > i)
	{
		dx = game->player->pos_x - game->bot[i].pos_x;
		dy = game->player->pos_y - game->bot[i].pos_y;
		dist = sqrtf(dx * dx + dy * dy);
		if (dist > 0.01f && game->bot[i].life == 1)
		{
			game->bot[i].pos_x += (dx / dist) * 0.01f * BOT_SPEED;
			game->bot[i].pos_y += (dy / dist) * 0.01f * BOT_SPEED;
		}
		i++;
		if (roundf(game->bot[i].pos_x) == roundf(game->player->pos_x)
			&& roundf(game->bot[i].pos_y) == roundf(game->player->pos_y))
			enemy_die(game, i);
	}
	game->ray->time_s++;
}
