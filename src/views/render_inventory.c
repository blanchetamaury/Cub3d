/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/16 13:23:36 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_inventory(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render_tmp, 0, 0);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_background, 153, 1);

	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_map, 299, 206);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_cases, 299, 304);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_save, 299, 400);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_options, 299, 498);

	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->q_arrow, 315, 595);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->e_arrow, 315, 109);
	if (game->events->exit)
	{
		change_view(game, 1);
		game->events->exit = 0;
	}
}