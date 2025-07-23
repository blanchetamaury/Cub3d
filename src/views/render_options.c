/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:18:58 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_option_tab_indicator(t_game *game)
{
	mlx_color	region[96 * 96];

	mlx_get_image_region(game->graphics->init,
		game->img[INVENTORY_ICON_MAP], 0, 0, 96, 96, region);
	set_region_opacity(region, 96 * 96, 128);
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		299, 206, 96, 96, region);
	mlx_get_image_region(game->graphics->init,
		game->img[INVENTORY_ICON_CASES], 0, 0, 96, 96, region);
	set_region_opacity(region, 96 * 96, 128);
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		299, 304, 96, 96, region);
	mlx_get_image_region(game->graphics->init,
		game->img[INVENTORY_ICON_SAVE], 0, 0, 96, 96, region);
	set_region_opacity(region, 96 * 96, 128);
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		299, 400, 96, 96, region);
	if (game->player->inventory_page == 3)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_OPTIONS_SELECTED], 299, 498);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_OPTIONS], 299, 498);
}

void	render_options(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[RENDER_TMP], 0, 0);
	game->player->angle = fmodf(game->player->angle + 0.1f, 360.0f);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[INVENTORY_BACKGROUND], 153, 1);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[Q_ARROW], 315, 595);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[E_ARROW], 315, 109);
	render_option_tab_indicator(game);
	render_inventory_page(game);
	mlx_mouse_show(game->graphics->init);
}
