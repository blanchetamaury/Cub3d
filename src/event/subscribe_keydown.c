/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_keydown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:04:46 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 15:49:19 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	on_keydown(int key, void *param)
{
	t_game	*game;

	game = param;
	if (game->graphics->view == 2)
		return (on_keydown_inventory(key, game));
	if (key == 26)
		game->events->move_forward = 1;
	else if (key == 22)
		game->events->move_backward = 1;
	else if (key == 4)
		game->events->move_left = 1;
	else if (key == 7)
		game->events->move_right = 1;
	else if (key == 79)
		game->events->rotate_left = 1;
	else if (key == 80)
		game->events->rotate_right = 1;
	else if (key == 41)
		game->events->exit = 1;
	else if (key == 8)
		game->events->inventory = 1;
	else if (key == 60)
		game->events->debug_enabled = !game->events->debug_enabled;
	else if (key == 15)
		game->ray->light = game->ray->light == LIGHT_ON ? LIGHT_OFF:LIGHT_ON;
}

void	subscribe_keydown(t_game *game)
{
	mlx_on_event(game->graphics->init, game->graphics->window, MLX_KEYDOWN,
		on_keydown, game);
}
