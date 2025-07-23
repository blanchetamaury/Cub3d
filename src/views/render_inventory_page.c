/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory_page.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:19:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:14:38 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_inventory_page(t_game *game)
{
	if (game->player->inventory_page == 0)
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[MINIMAP_HEADER], 511, 177);
		minimap(game, 516, 257);
	}
	if (game->player->inventory_page == 3)
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[OPTIONS_HEADER], 511, 177);
		render_options_page(game);
	}
}
