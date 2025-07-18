/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_inventory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:49:08 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/17 16:09:11 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_shadow_text(t_game *game, int x, int y, char *text)
{
	mlx_string_put(game->graphics->init, game->graphics->window, x, y, color(0x000000FF), text);
}

void	value_text(char *text, int value, int x, int y, t_game *game)
{
	char	*value_str;
	char	*full_text;

	value_str = ft_itoa(value);
	full_text = ft_strjoin(text, value_str);
	free(value_str);
	render_shadow_text(game, x, y, full_text);
	free(full_text);
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

	if (game->player->inventory_page == 0) // Options page
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->minimap_header, 511, 177);


		int postion_x = 516;
		int postion_y = 257;

		int	base_x;
		int base_y;
		int x;
		int y;


		base_y = (int)game->player->pos_y - 7;
		base_x = (int)game->player->pos_x - 7;
		if (base_y < 0)
			base_y = 0;
		if (base_x < 0)
			base_x = 0;
		postion_y -= base_y * 32;
		postion_x -= base_x * 32;
		y = base_y;
		while (game->map->map[y] && y < base_y + 12) {
			x = base_x;
			while (game->map->map[y][x] && x < base_x + 14) {
				if (game->map->map[y][x] == '1') {
					if ((x > 0 && game->map->map[y][x] != game->map->map[y][x - 1]) || x == 0)
						mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->map_r, postion_x + x * 32, postion_y + y * 32);
					if ((game->map->map[y][x + 1] && game->map->map[y][x] != game->map->map[y][x + 1]) || !game->map->map[y][x + 1])
						mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->map_l, postion_x + x * 32, postion_y + y * 32);
					if ((y > 0 && game->map->map[y][x] != game->map->map[y - 1][x]) || y == 0)
						mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->map_t, postion_x + x * 32, postion_y + y * 32);
					if ((game->map->map[y + 1] && game->map->map[y][x] != game->map->map[y + 1][x]) || !game->map->map[y + 1])
						mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->map_b, postion_x + x * 32, postion_y + y * 32);
				}
				if (y == (int)game->player->pos_y && x == (int)game->player->pos_x)
					mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->map_p, postion_x + x * 32, postion_y + y * 32);
				x++;
			}
			y++;
		}
	}

	if (game->player->inventory_page == 3) // Options page
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->options_header, 511, 177);

		if (game->player->selected_item == 0)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_selected, 511, 297);
		value_text("FOV: ", game->ray->fov, 531, 326, game);
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_base, 511, 297);
		progress((game->ray->fov / 10) - 4, 576, 331, game);

		if (game->player->selected_item == 1)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_selected, 511, 403);
		value_text("MAX FPS: ", game->graphics->max_fps, 531, 433, game);
		mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->texture->slider_base, 511, 403);
		progress((game->graphics->max_fps / 30) - 1, 576, 437, game);


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