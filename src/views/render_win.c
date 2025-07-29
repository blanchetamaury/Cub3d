/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:05:19 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/26 12:59:53 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_win_bg(t_game *game)
{
	static mlx_color	fade[1280 * 800];

	game->player->pos_x = (int)game->player->pos_x + 0.5f;
	game->player->pos_y = (int)game->player->pos_y + 0.5f;
	mlx_clear_window(game->graphics->init, game->graphics->window,
		color(0x000000FF));
	mlx_put_transformed_image_to_window(game->graphics->init,
		game->graphics->window, game->img[RENDER_TMP],
		-(min(game->graphics->frame * 16, 1920)),
		-(min(game->graphics->frame * 11, 1320)),
		minf(game->graphics->frame * 0.025f + 1, 4),
		minf(game->graphics->frame * 0.025f + 1, 4),
		minf(game->graphics->frame * 0.025f, 3));
	mlx_get_image_region(game->graphics->init, game->img[FADE],
		0, 0, 1280, 800, fade);
	set_region_opacity(fade, 1280 * 800,
		max(128 - game->graphics->frame, 10));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		0, 0, 1280, 800, fade);
}

void	put_retry_to_win(t_game *game)
{
	mlx_color	color[124 * 59];

	if (game->graphics->frame < 25)
		return ;
	if (game->graphics->selection == 1)
		mlx_get_image_region(game->graphics->init,
			game->img[RETRY_BUTTON_ACTIVE], 0, 0, 124, 59, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[RETRY_BUTTON],
			0, 0, 124, 59, color);
	set_region_opacity(color, 124 * 59,
		min((game->graphics->frame - 25) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		578, 397, 124, 59, color);
}

void	put_menu_to_win(t_game *game)
{
	mlx_color	color[293 * 59];

	if (game->graphics->frame < 35)
		return ;
	if (game->graphics->selection == 2)
		mlx_get_image_region(game->graphics->init,
			game->img[MENU_BUTTON_ACTIVE], 0, 0, 293, 59, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[MENU_BUTTON],
			0, 0, 293, 59, color);
	set_region_opacity(color, 293 * 59,
		min((game->graphics->frame - 35) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		494, 471, 293, 59, color);
}

void	put_exit_to_win(t_game *game)
{
	mlx_color	color[88 * 60];

	if (game->graphics->frame < 45)
		return ;
	if (game->graphics->selection == 3)
		mlx_get_image_region(game->graphics->init,
			game->img[EXIT_BUTTON_SELECTED], 0, 0, 88, 60, color);
	else
		mlx_get_image_region(game->graphics->init, game->img[EXIT_BUTTON],
			0, 0, 88, 60, color);
	set_region_opacity(color, 88 * 60,
		min((game->graphics->frame - 45) * 20, 255));
	mlx_pixel_put_region(game->graphics->init, game->graphics->window,
		596, 545, 88, 60, color);
}

void	render_win(t_game *game)
{
	float	scale;
	int		mx;
	int		my;

	render_win_bg(game);
	scale = minf(game->graphics->frame * 0.025f, 1);
	mlx_put_transformed_image_to_window(game->graphics->init,
		game->graphics->window, game->img[ESCAPED_TITLE],
		(WIDTH_WINDOW - (903 * scale)) / 2,
		((HEIGHT_WINDOW - (184 * scale)) / 2) - 200,
		scale, scale, 0.0f);
	put_retry_to_win(game);
	put_menu_to_win(game);
	put_exit_to_win(game);
	mlx_mouse_get_pos(game->graphics->init, &mx, &my);
	if (mx >= 578 && mx <= 702 && my >= 397 && my <= 456)
		game->graphics->selection = 1;
	else if (mx >= 494 && mx <= 787 && my >= 471 && my <= 530)
		game->graphics->selection = 2;
	else if (mx >= 596 && mx <= 684 && my >= 545 && my <= 605)
		game->graphics->selection = 3;
	else
		game->graphics->selection = 0;
	if (game->events->exit)
		mlx_loop_end(game->graphics->init);
}
