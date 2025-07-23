/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:26:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:14:06 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_logo_to_window(t_game *game)
{
	mlx_color	color[316 * 107];

	mlx_get_image_region(game->graphics->init, game->img[CUB3D_LOGO],
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
			game->img[PLAY_BUTTON_SELECTED], 0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[PLAY_BUTTON],
			0, 0, 88, 60, color);
	set_region_opacity(color, 88 * 60,
		min((game->graphics->frame - 15) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 332, 88, 60, color);
}

void	put_option_to_window(t_game *game)
{
	mlx_color	color[135 * 60];

	if (game->graphics->frame < 30)
		return ;
	if (game->graphics->selection == 3)
		mlx_get_image_region(game->graphics->init,
			game->img[OPTION_BUTTON_SELECTED], 0, 0, 135, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[OPTION_BUTTON],
			0, 0, 135, 60, color);
	set_region_opacity(color, 135 * 60,
		min((game->graphics->frame - 30) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 406, 135, 60, color);
}

void	put_exit_to_window(t_game *game)
{
	mlx_color	color[88 * 60];

	if (game->graphics->frame < 45)
		return ;
	if (game->graphics->selection == 4)
		mlx_get_image_region(game->graphics->init,
			game->img[EXIT_BUTTON_SELECTED], 0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[EXIT_BUTTON],
			0, 0, 88, 60, color);
	set_region_opacity(color, 88 * 60,
		min((game->graphics->frame - 45) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		40, 480, 88, 60, color);
}

void	render_menu(t_game *game)
{
	int		mx;
	int		my;

	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[RENDER_TMP], 0, 0);
	game->player->angle = fmodf(game->player->angle + 0.1f, 360.0f);
	put_logo_to_window(game);
	put_play_to_window(game);
	put_option_to_window(game);
	put_exit_to_window(game);
	mlx_mouse_get_pos(game->graphics->init, &mx, &my);
	if (mx >= 40 && mx <= 128 && my >= 332 && my <= 406)
		game->graphics->selection = 1;
	else if (mx >= 40 && mx <= 175 && my >= 406 && my <= 480)
		game->graphics->selection = 3;
	else if (mx >= 40 && mx <= 128 && my >= 480 && my <= 540)
		game->graphics->selection = 4;
	else
		game->graphics->selection = 0;
	game->graphics->frame++;
}
