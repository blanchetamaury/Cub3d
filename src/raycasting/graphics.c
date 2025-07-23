/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/23 09:47:25 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting_task(void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	raycasting(game);
}

void	add_battery(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == '0' && rand() % 40 == 0)
				game->map->map[y][x] = 'B';
			x++;
		}
		printf("%s\n", game->map->map[y]);
		y++;
	}
}

void	graphic(t_game *game)
{
	game->ray->deltaangle = game->ray->fov / (float)WIDTH_WINDOW;
	game->ray->deg_to_rad = 3.14 / 180.0f;
	game->ray->frame = 0;
	if (is_bonus())
		add_battery(game);
	mlx_set_font_scale(game->graphics->init,
		"assets/fonts/SuperLegendBoy.ttf", 22);
	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_add_loop_hook(game->graphics->init, raycasting_task, game);
	mlx_loop(game->graphics->init);
}
