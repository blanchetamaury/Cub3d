/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:45:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/28 15:43:10 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	battery_manager(t_game *game)
{
	if (game->ray->light == LIGHT_ON)
		game->player->battery--;
	if (game->player->battery <= 0)
		game->ray->light = LIGHT_OFF;
	if (game->map->map[(int)game->player->pos_y][(int)game->player->pos_x]
			== 'B' && game->player->battery < (200) * 6)
	{
		game->map->map[(int)game->player->pos_y][(int)game->player->pos_x]
			= '0';
		game->player->battery += 20 * 10;
	}
}

static void	spawn_enemy(t_game *game)
{
	int		max_x;
	int		i;
	int		status;

	status = 0;
	if (game->ray->count_frame >= game->graphics->max_fps * TIME_SPAWN)
	{
		i = 0;
		game->ray->count_frame = 0;
		while (i < game->ray->count_bot)
		{
			printf(" BOT %d = life %d\n", i, game->bot[i].life);
			if (game->bot[i].life == 0)
			{
				max_x = ft_strlen(game->map->map[(int)game->player->pos_y]);
				if (rand() % 2 == 0)
					game->bot[i].pos_x = max(0,
							(int)game->player->base_pos_x - rand()
							% ((int)game->player->base_pos_x - 1));
				else
					game->bot[i].pos_x = max(max_x - 1,
							(int)game->player->base_pos_x + rand()
							% (max_x - (int)game->player->base_pos_x));
				if (rand() % 2 == 0)
					game->bot[i].pos_y = max(0,
							(int)game->player->base_pos_y - rand()
							% ((int)game->player->base_pos_y - 1));
				else
					game->bot[i].pos_y = max(game->map->size - 1,
							(int)game->player->base_pos_y + rand()
							% ((game->map->size - 1) - (int)game->player->base_pos_y));
				game->bot[i].life = 1;
				status = 1;
				break ;
			}
			i++;
		}
		if (status == 0 && game->ray->count_bot < NB_BOT)
		{
			max_x = ft_strlen(game->map->map[(int)game->player->pos_y]);
			if (rand() % 2 == 0)
				game->bot[game->ray->count_bot].pos_x = max(0,
						(int)game->player->base_pos_x - rand()
						% ((int)game->player->base_pos_x - 1));
			else
				game->bot[game->ray->count_bot].pos_x = max(max_x - 1,
						(int)game->player->base_pos_x + rand()
						% (max_x - (int)game->player->base_pos_x));
			if (rand() % 2 == 0)
				game->bot[game->ray->count_bot].pos_y = max(0,
						(int)game->player->base_pos_y - rand()
						% ((int)game->player->base_pos_y - 1));
			else
				game->bot[game->ray->count_bot].pos_y = max(game->map->size - 1,
						(int)game->player->base_pos_y + rand()
						% ((game->map->size - 1) - (int)game->player->base_pos_y));
			game->bot[game->ray->count_bot].life = 1;
			game->ray->count_bot++;
		}
		printf("\n");
	}
}

static void enemy_manager(t_game *game)
{
	int		enemy_index;
	float	dx;
	float	dy;
	float	dist;

	spawn_enemy(game);
	enemy_index = 0;
	while (game->ray->count_bot > enemy_index)
	{
		dx = game->player->pos_x - game->bot[enemy_index].pos_x;
		dy = game->player->pos_y - game->bot[enemy_index].pos_y;
		dist = sqrtf(dx * dx + dy * dy);
		if (dist > 0.01f && game->bot[enemy_index].life == 1)
		{
			game->bot[enemy_index].pos_x += (dx / dist) * 0.01f * BOT_SPEED;
			game->bot[enemy_index].pos_y += (dy / dist) * 0.01f * BOT_SPEED;
		}
		enemy_index++;
	}
	game->ray->time_s++;
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[RENDER_TMP], 0, 0);
	compass(game);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[CROSSHAIR], (WIDTH_WINDOW / 2) - 40,
		(HEIGHT_WINDOW / 2) + 20);
	player_action(game);
	hand(game);
	if (is_bonus())
	{
		flashlight_panel(game);
		battery_manager(game);
		enemy_manager(game);
	}
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[CLOCK_BACKGROUND], 0, HEIGHT_WINDOW - 128);
	game->ray->count_frame++;
}
