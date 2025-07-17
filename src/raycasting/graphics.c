/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 15:20:42 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting_task(void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	raycasting(game);
}

void	graphic(t_game *game)
{
	game->ray->deltaangle = game->ray->fov / (float)WIDTH_WINDOW;
	game->ray->deg_to_rad = 3.14 / 180.0f;

	mlx_set_font_scale(game->graphics->init, "assets/fonts/SuperLegendBoy.ttf", 22);

	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_add_loop_hook(game->graphics->init, raycasting_task, game);
	mlx_loop(game->graphics->init);
}
