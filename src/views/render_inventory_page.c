/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory_page.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:19:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 13:17:16 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_inventory_page(t_game *game)
{
	if (game->player->inventory_page == 0)
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->minimap_header, 511, 177);
		minimap(game, 516, 257);
	}
	if (game->player->inventory_page == 3)
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->options_header, 511, 177);
		render_options_page(game);
	}
}
