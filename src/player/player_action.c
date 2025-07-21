/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:10 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/21 15:34:42 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	player_mouse_rotation(t_game *game)
{
	int		mx;
	int		my;

	mlx_mouse_hide(game->graphics->init);
	mlx_mouse_get_pos(game->graphics->init, &mx, &my);
	if ((mx / (float) WIDTH_WINDOW) * 360.0f == 0
		&& game->graphics->frame % 3 == 0)
		mlx_mouse_move(game->graphics->init, game->graphics->window,
			WIDTH_WINDOW - 2, HEIGHT_WINDOW / 2);
	else if ((mx / (float) WIDTH_WINDOW) * 360.0f > 359.0f
		&& game->graphics->frame % 3 == 0)
		mlx_mouse_move(game->graphics->init, game->graphics->window,
			2, HEIGHT_WINDOW / 2);
	game->player->angle = (mx / (float) WIDTH_WINDOW) * 360.0f;
}

void	player_action(t_game *game)
{
	static float	previous_rotation = 2.0f;

	player_move_backward(game);
	player_move_forward(game);
	player_move_left(game);
	player_move_right(game);
	player_rotate_left(game, previous_rotation);
	player_rotate_right(game, previous_rotation);
	player_exit(game);
	if (game->events->inventory)
	{
		change_view(game, 2);
		game->events->inventory = 0;
	}
	if (!game->events->rotate_left && !game->events->rotate_right)
		previous_rotation = 2.0f;
	if (game->player->use_mouse_rotation)
		player_mouse_rotation(game);
}
