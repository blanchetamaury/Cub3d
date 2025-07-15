/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/15 15:52:45 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_inventory(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render_tmp, 0, 0);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_background, 153, 1);

	if (game->events->exit)
	{
		change_view(game, 1);
		game->events->exit = 0;
	}
}