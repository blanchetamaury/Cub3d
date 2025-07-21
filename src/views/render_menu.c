/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:26:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 13:48:44 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_logo_to_window(t_game *game)
{
	mlx_color	color[316 * 107];

	mlx_get_image_region(game->graphics->init, game->texture->cub3d_logo,
		0, 0, 316, 107, color);
	set_region_opacity(color, 316 * 107,
		min(game->graphics->frame * 10, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		min(20 + game->graphics->frame, 40), 40, 316, 107,
		color);
}

void	put_play_to_window(t_game *game)
{
	mlx_color	color[88 * 60];

	if (game->graphics->frame < 15)
		return ;
	if (game->graphics->selection == 1)
		mlx_get_image_region(game->graphics->init,
			game->texture->play_button_selected, 0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->play_button,
			0, 0, 88, 60, color);
	set_region_opacity(color, 88 * 60,
		min((game->graphics->frame - 15) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 295, 88, 60, color);
}

void	put_option_to_window(t_game *game)
{
	mlx_color	color[135 * 60];

	if (game->graphics->frame < 25)
		return ;
	if (game->graphics->selection == 3)
		mlx_get_image_region(game->graphics->init,
			game->texture->option_button_selected, 0, 0, 135, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->option_button,
			0, 0, 135, 60, color);
	set_region_opacity(color, 135 * 60,
		min((game->graphics->frame - 25) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 442, 135, 60, color);
}

void	put_exit_to_window(t_game *game)
{
	mlx_color	color[88 * 60];

	if (game->graphics->frame < 30)
		return ;
	if (game->graphics->selection == 4)
		mlx_get_image_region(game->graphics->init,
			game->texture->exit_button_selected, 0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->texture->exit_button,
			0, 0, 88, 60, color);
	set_region_opacity(color, 88 * 60,
		min((game->graphics->frame - 30) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 516,
		88, 60,
		color);
}

void	render_menu(t_game *game)
{
	int		mx;
	int		my;

	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->texture->render_tmp, 0, 0);
	game->player->angle = fmodf(game->player->angle + 0.1f, 360.0f);
	put_logo_to_window(game);
	put_play_to_window(game);
	put_option_to_window(game);
	put_exit_to_window(game);
	mlx_mouse_get_pos(game->graphics->init, &mx, &my);
	if (mx >= 40 && mx <= 128 && my >= 294 && my <= 368)
		game->graphics->selection = 1;
	else if (mx >= 40 && mx <= 175 && my >= 440 && my <= 514)
		game->graphics->selection = 3;
	else if (mx >= 40 && mx <= 128 && my >= 514 && my <= 574)
		game->graphics->selection = 4;
	else
		game->graphics->selection = 0;
	game->graphics->frame++;
}
