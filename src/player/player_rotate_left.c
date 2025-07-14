/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:10:05 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 11:18:56 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	player_rotate_left(t_game *game, float previous_rotation)
{
	if (game->events->rotate_left)
	{
		game->player->angle = fmodf(game->player->angle
				+ previous_rotation, 360.0f);
		previous_rotation += 0.025f;
		if (previous_rotation > 10)
			previous_rotation = 10.0f;
	}
	return (previous_rotation);
}
