/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:45:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 14:25:17 by rgodet           ###   ########.fr       */
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
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render, 0, 0);

	if (game->events->move_forward) // W
	{
		float x = game->player->pos_x + (cos(deg_to_rad(game->player->angle)) * 0.1);
		float y = game->player->pos_y + (sin(deg_to_rad(game->player->angle)) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
	if (game->events->move_backward) // S
	{
		float x = game->player->pos_x - (cos(deg_to_rad(game->player->angle)) * 0.1);
		float y = game->player->pos_y - (sin(deg_to_rad(game->player->angle)) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
	if (game->events->move_left) // A
	{
		float angle_rad = deg_to_rad(game->player->angle - 90);
		float x = game->player->pos_x + (cos(angle_rad) * 0.1);
		float y = game->player->pos_y + (sin(angle_rad) * 0.1);
		apply_position(game->player, game->map, x, y);
	}

	if (game->events->move_right) // D
	{
		float angle_rad = deg_to_rad(game->player->angle + 90);
		float x = game->player->pos_x + (cos(angle_rad) * 0.1);
		float y = game->player->pos_y + (sin(angle_rad) * 0.1);
		apply_position(game->player, game->map, x, y);
	}
	if (game->events->exit) // Escape
		mlx_loop_end(game->graphics->init);

	if (game->events->rotate_left) // Left arrow
		game->player->angle = (game->player->angle + 2) % 360;
	if (game->events->rotate_right) // Right arrow
		game->player->angle = (game->player->angle - 2) % 360;

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
	if (game->events->debug_enabled)
		debug_view(game);

	// int mouse_x = width_window/2;
	// int mouse_y = 0;
	// mlx_mouse_get_pos(game->graphics->init, &mouse_x, &mouse_y);
	// if ((mouse_x / (float)width_window) * 360.0f == 0 && game->graphics->frame % 3 == 0)
	// 	mlx_mouse_move(game->graphics->init, game->graphics->window, width_window - 2, height_window/2);
	// else if ((mouse_x / (float)width_window) * 360.0f > 359.0f && game->graphics->frame % 3 == 0)
	// 	mlx_mouse_move(game->graphics->init, game->graphics->window, 2, height_window/2);
	// game->player->angle = (mouse_x / (float)width_window) * 360.0f;
	//
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->north->img, 0, 0, 0.25, 0.25, 0);
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->south->img, game->texture->north->width * 0.25 + 10, 0, 0.25, 0.25, 0);
	//
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->west->img, 0, game->texture->north->height * 0.25 + 10, 0.25, 0.25, 0);
	// mlx_put_transformed_image_to_window(game->graphics->init, game->graphics->window, game->texture->east->img, game->texture->west->width * 0.25 + 10, game->texture->south->height * 0.25 + 10, 0.25, 0.25, 0);

	game->graphics->frame++;
}