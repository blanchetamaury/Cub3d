/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:45:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/18 11:00:38 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_color	color(uint32_t color)
{
	mlx_color	c;

	c.rgba = color;
	return (c);
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));

	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render_tmp, 0, 0);
	(void) draw_rectangle;
	compass(game);
	hand(game);

	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->flash_panel, WIDTH_WINDOW - 154, HEIGHT_WINDOW - 246);
	if (!game->events->flashlight)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->flash_on, WIDTH_WINDOW - 82, HEIGHT_WINDOW - 74);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->flash_off, WIDTH_WINDOW - 82, HEIGHT_WINDOW - 74);

	int i = 1;

	while (i <= 6 && game->player->battery > (i * 600) - 600) {
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->led_on, 1164, 734 - (i - 1) * 18.5f);
		i++;
	}


	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->clock_background, 0, HEIGHT_WINDOW - 128);

	if (game->events->debug_enabled)
		debug_view(game);

	if (game->player->use_mouse_rotation)
	{
		mlx_mouse_hide(game->graphics->init);
		int mouse_x = WIDTH_WINDOW / 2;
		int mouse_y = 0;
		mlx_mouse_get_pos(game->graphics->init, &mouse_x, &mouse_y);
		if ((mouse_x / (float) WIDTH_WINDOW) * 360.0f == 0 && game->graphics->frame % 3 == 0)
			mlx_mouse_move(game->graphics->init, game->graphics->window, WIDTH_WINDOW - 2, HEIGHT_WINDOW / 2);
		else if ((mouse_x / (float) WIDTH_WINDOW) * 360.0f > 359.0f && game->graphics->frame % 3 == 0)
			mlx_mouse_move(game->graphics->init, game->graphics->window, 2, HEIGHT_WINDOW / 2);
		game->player->angle = (mouse_x / (float) WIDTH_WINDOW) * 360.0f;
	}
	player_action(game);
	if (!game->events->flashlight && game->player->battery > 0)
		game->player->battery--;
	if (game->player->battery == 0)
		game->events->flashlight = 1;

	if (game->map->map[(int)game->player->pos_y][(int)game->player->pos_x] == 'B' && game->player->battery < 3600 - 600)
	{
		game->map->map[(int)game->player->pos_y][(int)game->player->pos_x] = '0';
		game->player->battery += 600;
	}
	game->graphics->frame++;
}