/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:44:55 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/28 10:35:21 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_view(t_game *game, int view)
{
	mlx_mouse_show(game->graphics->init);
	game->graphics->view = view;
	game->graphics->frame = 0;
}

void	counter_time(t_game *game, double end_time, double start_time)
{
	if (is_bonus())
	{
		end_time = get_time_in_seconds();
		game->graphics->fps = 1.0 / (end_time - start_time);
		if (game->events->debug_enabled)
			debug_fps(game);
	}
}

void	render(void *data)
{
	double		start_time;
	t_game		*game;

	game = (t_game *)data;
	if (is_bonus())
		start_time = get_time_in_seconds();
	else
		start_time = 0;
	if (game->graphics->view == 0)
		render_menu(game);
	else if (game->graphics->view == 1)
		render_game(game);
	else if (game->graphics->view == 2)
		render_inventory(game);
	else if (game->graphics->view == 3)
		render_options(game);
	else if (game->graphics->view == 4)
		render_win(game);
	else if (game->graphics->view == 5)
		render_lose(game);
	counter_time(game, 0, start_time);
	game->graphics->frame++;
	game->ray->frame++;
}
