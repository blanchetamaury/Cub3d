/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_keydown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:04:46 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/26 12:57:49 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	on_keydown_move_player(int key, t_game *game)
{
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
	else
		return (0);
	return (1);
}

static void	on_keydown(int key, void *param)
{
	t_game	*game;

	game = param;
	if (game->graphics->view == 2)
		return (on_keydown_inventory(key, game));
	if (game->graphics->view == 3)
		return (on_keydown_options(key, game));
	if (on_keydown_move_player(key, game) == 0)
	{
		if (key == 41)
			game->events->exit = 1;
		else if (key == 8)
			game->events->inventory = 1;
		else if (key == 60)
			game->events->debug_enabled = !game->events->debug_enabled;
		else if (key == 15)
		{
			if (game->ray->light == LIGHT_ON)
				game->ray->light = LIGHT_OFF;
			else
				game->ray->light = LIGHT_ON;
		}
	}
}

void	subscribe_keydown(t_game *game)
{
	mlx_on_event(game->graphics->init, game->graphics->window, MLX_KEYDOWN,
		on_keydown, game);
}
