/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 13:31:44 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_tab_indicator(t_game *game)
{
	if (game->player->inventory_page == 0)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_map_selected, 299, 206);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_map, 299, 206);
	if (game->player->inventory_page == 1)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_cases_selected, 299, 304);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_cases, 299, 304);
	if (game->player->inventory_page == 2)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_save_selected, 299, 400);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_save, 299, 400);
	if (game->player->inventory_page == 3)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_options_selected, 299, 498);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->inventory_icon_options, 299, 498);
}

void	render_inventory(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->render_tmp, 0, 0);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->inventory_background, 153, 1);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->q_arrow, 315, 595);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->e_arrow, 315, 109);
	render_tab_indicator(game);
	render_inventory_page(game);
}
