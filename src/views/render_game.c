/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:45:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:12:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	battery_manager(t_game *game)
{
	if (!game->events->flashlight && game->player->battery > 0)
		game->player->battery--;
	if (game->player->battery == 0)
		game->events->flashlight = 1;
	if (game->map->map[(int)game->player->pos_y][(int)game->player->pos_x]
			== 'B' && game->player->battery < 3600 - 600)
	{
		game->map->map[(int)game->player->pos_y][(int)game->player->pos_x]
			= '0';
		game->player->battery += 600;
	}
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
	if (is_bonus())
	{
		hand(game);
		flashlight_panel(game);
		battery_manager(game);
	}
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[CLOCK_BACKGROUND], 0, HEIGHT_WINDOW - 128);
}
