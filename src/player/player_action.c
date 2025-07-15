/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:04:10 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 11:18:49 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
}
