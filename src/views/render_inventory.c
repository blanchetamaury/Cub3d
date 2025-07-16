/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/16 15:46:49 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_shadow_text(t_game *game, int x, int y, char *text)
{
	mlx_string_put(game->graphics->init, game->graphics->window, x, y, color(0x000000FF), text);
}

void	render_inventory(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window, color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->render_tmp, 0, 0);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_background, 153, 1);

	if (game->player->inventory_page == 0)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_map_selected, 299, 206);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_map, 299, 206);
	if (game->player->inventory_page == 1)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_cases_selected, 299, 304);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_cases, 299, 304);
	if (game->player->inventory_page == 2)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_save_selected, 299, 400);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_save, 299, 400);
	if (game->player->inventory_page == 3)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_options_selected, 299, 498);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->inventory_icon_options, 299, 498);

	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->q_arrow, 315, 595);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->e_arrow, 315, 109);

	if (game->player->inventory_page == 3) // Options page
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->options_header, 511, 177);

		if (game->player->selected_item == 0)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_selected, 511, 297);
		render_shadow_text(game, 531, 326, "FOV: 70");
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_base, 511, 297);

		if (game->player->selected_item == 1)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_selected, 511, 403);
		render_shadow_text(game, 531, 433, "MAX FPS: 120");
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_base, 511, 403);

		if (game->player->selected_item == 2)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->switch_selected, 511, 509);
		render_shadow_text(game, 595, 556, "Rotate camera with mouse");
		if (game->player->use_mouse_rotation)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->switch_on, 521, 519);
		else
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->switch_off, 521, 519);
	}
	if (game->events->exit)
	{
		change_view(game, 1);
		game->events->exit = 0;
	}
}