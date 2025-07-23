/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:16:32 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_tab_indicator(t_game *game)
{
	if (game->player->inventory_page == 0)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_MAP_SELECTED], 299, 206);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_MAP], 299, 206);
	if (game->player->inventory_page == 1)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_CASES_SELECTED], 299, 304);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_CASES], 299, 304);
	if (game->player->inventory_page == 2)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_SAVE_SELECTED], 299, 400);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_SAVE], 299, 400);
	if (game->player->inventory_page == 3)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_OPTIONS_SELECTED], 299, 498);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[INVENTORY_ICON_OPTIONS], 299, 498);
}

void	render_inventory(t_game *game)
{
	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[RENDER_TMP], 0, 0);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[INVENTORY_BACKGROUND], 153, 1);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[Q_ARROW], 315, 595);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[E_ARROW], 315, 109);
	render_tab_indicator(game);
	render_inventory_page(game);
	mlx_mouse_show(game->graphics->init);
}
