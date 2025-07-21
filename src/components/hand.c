/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:27:04 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/18 15:16:37 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	hand(t_game *game)
{
	if (game->events->move_forward || game->events->move_backward
		|| game->events->move_left || game->events->move_right)
	{
		if (game->graphics->frame % 30 >= 15)
			mlx_put_image_to_window(
				game->graphics->init, game->graphics->window,
				game->texture->hands, 0,
				HEIGHT_WINDOW - 590 - (game->graphics->frame % 15) / 2);
		else
			mlx_put_image_to_window(
				game->graphics->init, game->graphics->window,
				game->texture->hands, 0,
				HEIGHT_WINDOW - 590 - (15 - game->graphics->frame % 15) / 2);
	}
	else
		mlx_put_image_to_window(
			game->graphics->init, game->graphics->window,
			game->texture->hands, 0, HEIGHT_WINDOW - 590);
}
