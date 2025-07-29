/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:56:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/29 12:36:07 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_bot_position(t_bot *bot, t_game *game)
{
	int		max_x;

	max_x = ft_strlen(game->map->map[(int)game->player->pos_y]);
	if (rand() % 2 == 0)
		bot->pos_x = max(0, (int)game->player->base_pos_x - rand()
				% ((int)game->player->base_pos_x - 1));
	else
		bot->pos_x = max(max_x - 1, (int)game->player->base_pos_x + rand()
				% (max_x - (int)game->player->base_pos_x));
	if (rand() % 2 == 0)
		bot->pos_y = max(0, (int)game->player->base_pos_y - rand()
				% ((int)game->player->base_pos_y - 1));
	else
		bot->pos_y = max(game->map->size - 1,
				(int)game->player->base_pos_y + rand()
				% ((game->map->size - 1) - (int)game->player->base_pos_y));
}

void	spawn_enemy(t_game *game)
{
	int		i;
	int		status;

	status = 0;
	if (game->ray->count_frame >= game->graphics->max_fps * TIME_SPAWN)
	{
		i = 0;
		game->ray->count_frame = 0;
		while (i < game->ray->count_bot)
		{
			if (game->bot[i].life == 0)
			{
				set_bot_position(&game->bot[i], game);
				game->bot[i].life = 1;
				status = 1;
				break ;
			}
			i++;
		}
		if (status == 0 && game->ray->count_bot < NB_BOT)
		{
			set_bot_position(&game->bot[game->ray->count_bot], game);
			game->bot[game->ray->count_bot++].life = 1;
		}
	}
}
