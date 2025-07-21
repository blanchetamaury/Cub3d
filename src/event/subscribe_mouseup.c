/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_mouseup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:07:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 17:30:54 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	on_mouseup(int key, void *param)
{
	t_game	*game;

	game = param;
	if (game->graphics->view == 0 && game->graphics->selection == 1)
	{
		change_view(game, 1);
		game->player->angle = game->player->base_angle;
	}
	if (game->graphics->view == 0 && game->graphics->selection == 4)
		mlx_loop_end(game->graphics->init);
	(void) key;
}

void	subscribe_mouseup(t_graphics *graphics, t_game *game)
{
	mlx_on_event(graphics->init, graphics->window, MLX_MOUSEUP,
		on_mouseup, game);
}
