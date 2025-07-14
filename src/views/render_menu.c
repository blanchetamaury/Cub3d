/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:26:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 14:17:12 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_logo_to_window(t_game *game)
{
	mlx_color	color[316 * 107];
	int			i;

	mlx_get_image_region(game->graphics->init, game->texture->cub3d_logo, 0, 0, 316, 107, color);
	i = 0;
	while (i < 316 * 107)
	{
		if (color[i].a > 0)
			color[i].a = min(game->graphics->frame * 10, 255);
		i++;
	}
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		min(20 + game->graphics->frame, 40), 40,
		316, 107,
		color);
}

void	put_play_to_window(t_game *game)
{
	mlx_color	color[88 * 60];
	int			i;

	if (game->graphics->frame < 15)
		return;
	if (game->graphics->selection == 1)
		mlx_get_image_region(game->graphics->init, game->texture->play_button_selected,
			0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->play_button,
			0, 0, 88, 60, color);
	i = 0;
	while (i < 88 * 60)
	{
		if (color[i].a > 127)
			color[i].a = min((game->graphics->frame - 15) * 20, 255);
		else if (color[i].a > 0)
			color[i].a = min(color[i].a * (game->graphics->frame - 15) / 20, color[i].a);
		i++;
	}
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 195,
		88, 60,
		color);
}

void	put_online_to_window(t_game *game)
{
	mlx_color	color[132 * 60];
	int			i;

	if (game->graphics->frame < 20)
		return;
	if (game->graphics->selection == 2)
		mlx_get_image_region(game->graphics->init, game->texture->online_button_selected,
			0, 0, 132, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->online_button,
			0, 0, 132, 60, color);
	i = 0;
	while (i < 132 * 60)
	{
		if (color[i].a > 127)
			color[i].a = min((game->graphics->frame - 20) * 20, 255);
		else if (color[i].a > 0)
			color[i].a = min(color[i].a * (game->graphics->frame - 20) / 20, color[i].a);
		i++;
	}
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 268,
		132, 60,
		color);
}

void	put_option_to_window(t_game *game)
{
	mlx_color	color[135 * 60];
	int			i;

	if (game->graphics->frame < 25)
		return;
	if (game->graphics->selection == 3)
		mlx_get_image_region(game->graphics->init, game->texture->option_button_selected,
			0, 0, 135, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->option_button,
			0, 0, 135, 60, color);
	i = 0;
	while (i < 135 * 60)
	{
		if (color[i].a > 127)
			color[i].a = min((game->graphics->frame - 25) * 20, 255);
		else if (color[i].a > 0)
			color[i].a = min(color[i].a * (game->graphics->frame - 25) / 20, color[i].a);
		i++;
	}
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 342,
		135, 60,
		color);
}

void	put_exit_to_window(t_game *game)
{
	mlx_color	color[88 * 60];
	int			i;

	if (game->graphics->frame < 30)
		return;
	if (game->graphics->selection == 4)
		mlx_get_image_region(game->graphics->init, game->texture->exit_button_selected,
			0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->exit_button,
			0, 0, 88, 60, color);
	i = 0;
	while (i < 88 * 60)
	{
		if (color[i].a > 127)
			color[i].a = min((game->graphics->frame - 30) * 20, 255);
		else if (color[i].a > 0)
			color[i].a = min(color[i].a * (game->graphics->frame - 30) / 20, color[i].a);
		i++;
	}
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 416,
		88, 60,
		color);
}

void	render_menu(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));

	raycasting(game);

	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->render, 0, 0);

	game->player->angle = fmodf(game->player->angle + 0.1f, 360.0f);
	put_logo_to_window(game);
	put_play_to_window(game);
	put_online_to_window(game);
	put_option_to_window(game);
	put_exit_to_window(game);

	int mouse_x, mouse_y;
	mlx_mouse_get_pos(game->graphics->init, &mouse_x, &mouse_y);
	if (mouse_x >= 40 && mouse_x <= 128 && mouse_y >= 195 && mouse_y <= 255)
		game->graphics->selection = 1;
	else if (mouse_x >= 40 && mouse_x <= 172 && mouse_y >= 268 && mouse_y <= 328)
		game->graphics->selection = 2;
	else if (mouse_x >= 40 && mouse_x <= 175 && mouse_y >= 342 && mouse_y <= 402)
		game->graphics->selection = 3;
	else if (mouse_x >= 40 && mouse_x <= 128 && mouse_y >= 416 && mouse_y <= 476)
		game->graphics->selection = 4;
	else
		game->graphics->selection = 0;
	game->graphics->frame++;
}