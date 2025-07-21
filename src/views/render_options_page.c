/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_options_page.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:12:46 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 13:22:04 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_text(t_game *game, int x, int y, char *text)
{
	mlx_string_put(game->graphics->init, game->graphics->window, x, y,
		color(0x000000FF), text);
}

void	value_text(char *text, int value, int y, t_game *game)
{
	char	*value_str;
	char	*full_text;

	value_str = ft_itoa(value);
	full_text = ft_strjoin(text, value_str);
	free(value_str);
	render_text(game, 531, y, full_text);
	free(full_text);
}

void	render_options_page(t_game *game)
{
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->options_header, 511, 177);
	if (game->player->selected_item == 0)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->slider_selected, 511, 297);
	value_text("FOV: ", game->ray->fov, 326, game);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->slider_base, 511, 297);
	progress((game->ray->fov / 10) - 4, 576, 331, game);
	if (game->player->selected_item == 1)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->slider_selected, 511, 403);
	value_text("MAX FPS: ", game->graphics->max_fps, 433, game);
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->slider_base, 511, 403);
	progress((game->graphics->max_fps / 30) - 1, 576, 437, game);
	if (game->player->selected_item == 2)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->switch_selected, 511, 509);
	render_text(game, 595, 556, "Rotate camera with mouse");
	switch_view(game, game->player->use_mouse_rotation, 521, 519);
}
