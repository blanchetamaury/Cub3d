/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:28:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 09:40:23 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	move_inventory(int key, t_game *game)
{
	if (key == 41)
	{
		change_view(game, 1);
		game->events->exit = 0;
	}
	if (key == 20)
		game->player->inventory_page = (game->player->inventory_page + 1) % 4;
	if (key == 8)
		game->player->inventory_page = (game->player->inventory_page - 1 + 4)
			% 4;
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

static void	inventory_settings(int key, t_game *game)
{
	if (key == 7)
	{
		if (game->player->inventory_page == 3)
		{
			if (game->player->selected_item == 0 && game->ray->fov < 100)
				game->ray->fov += 10;
			if (game->player->selected_item == 1)
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

void	on_keydown_inventory(int key, t_game *game)
{
	move_inventory(key, game);
	inventory_settings(key, game);
	if (key == 4)
	{
		if (game->player->inventory_page == 3)
		{
			if (game->player->selected_item == 0 && game->ray->fov > 40)
				game->ray->fov -= 10;
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
