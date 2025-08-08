/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:28:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/08/08 09:44:37 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	move_options(int key, t_game *game)
{
	if (key == 41)
		change_view(game, 0);
	if (key == 22)
	{
		if (game->player->inventory_page == 3)
			game->player->selected_item = (game->player->selected_item + 1) % 3;
	}
	if (key == 26)
	{
		if (game->player->inventory_page == 3)
			game->player->selected_item = (game->player->selected_item - 1 + 3)
				% 3;
	}
}

static void	settings(int key, t_game *game)
{
	if (key == 7)
	{
		if (game->player->inventory_page == 3)
		{
			if (game->player->selected_item == 0 && game->ray->fov < 100)
			{
				game->ray->fov += 10;
				game->ray->deltaangle = game->ray->fov / (float)WIDTH_WINDOW;
				game->ray->deg_to_rad = 3.14 / 180.0f;
			}
			if (game->player->selected_item == 1
				&& game->graphics->max_fps < 210)
			{
				game->graphics->max_fps += 30;
				mlx_set_fps_goal(game->graphics->init, game->graphics->max_fps);
			}
			if (game->player->selected_item == 2)
				game->player->use_mouse_rotation
					= !game->player->use_mouse_rotation;
		}
	}
}

void	on_keydown_options(int key, t_game *game)
{
	move_options(key, game);
	settings(key, game);
	if (key == 4)
	{
		if (game->player->inventory_page == 3)
		{
			if (game->player->selected_item == 0 && game->ray->fov > 40)
			{
				game->ray->fov -= 10;
				game->ray->deltaangle = game->ray->fov / (float)WIDTH_WINDOW;
				game->ray->deg_to_rad = 3.14 / 180.0f;
			}
			if (game->player->selected_item == 1
				&& game->graphics->max_fps > 30)
			{
				game->graphics->max_fps -= 30;
				mlx_set_fps_goal(game->graphics->init, game->graphics->max_fps);
			}
			if (game->player->selected_item == 2)
				game->player->use_mouse_rotation
					= !game->player->use_mouse_rotation;
		}
	}
}
