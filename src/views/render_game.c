/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:45:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 14:10:41 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_rectangle(t_game *game, int x, int y, int w, int h, uint32_t color)
{
	int	i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			mlx_pixel_put(game->graphics->init, game->graphics->window, x + j, y + i, (mlx_color){ .rgba = color });
			j++;
		}
		i++;
	}
}

mlx_color	color(uint32_t color)
{
	mlx_color	c;

	c.rgba = color;
	return (c);
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));

	raycasting(game);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render_tmp, 0, 0);
	(void) draw_rectangle;
	compass(game);
	if (game->events->move_forward || game->events->move_backward
		|| game->events->move_left || game->events->move_right)
	{
		if (game->graphics->frame % 30 >= 15)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->hands, 0, (game->graphics->frame % 15) / 2);
		else
		 	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->hands, 0, (15 - game->graphics->frame % 15) / 2);
	}
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->hands, 0, 0);


	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->clock_background, 0, HEIGHT_WINDOW - 143);

	if (game->events->debug_enabled)
		debug_view(game);
	// int mouse_x = WIDTH_WINDOW/2;
	// int mouse_y = 0;
	// mlx_mouse_get_pos(game->graphics->init, &mouse_x, &mouse_y);
	// if ((mouse_x / (float)WIDTH_WINDOW) * 360.0f == 0 && game->graphics->frame % 3 == 0)
	// 	mlx_mouse_move(game->graphics->init, game->graphics->window, WIDTH_WINDOW - 2, HEIGHT_WINDOW/2);
	// else if ((mouse_x / (float)WIDTH_WINDOW) * 360.0f > 359.0f && game->graphics->frame % 3 == 0)
	// 	mlx_mouse_move(game->graphics->init, game->graphics->window, 2, HEIGHT_WINDOW/2);
	// game->player->angle = (mouse_x / (float)WIDTH_WINDOW) * 360.0f;
	//
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->north->img, 0, 0, 0.25, 0.25, 0);
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->south->img, game->texture->north->width * 0.25 + 10, 0, 0.25, 0.25, 0);
	//
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->west->img, 0, game->texture->north->height * 0.25 + 10, 0.25, 0.25, 0);
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->east->img, game->texture->west->width * 0.25 + 10, game->texture->south->height * 0.25 + 10, 0.25, 0.25, 0);
	player_action(game);
	game->graphics->frame++;
}