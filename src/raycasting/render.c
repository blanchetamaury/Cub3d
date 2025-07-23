/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:44:55 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 13:05:44 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_view(t_game *game, int view)
{
	mlx_mouse_show(game->graphics->init);
	game->graphics->view = view;
	game->graphics->frame = 0;
}

void	render(void *data)
{
	double		start_time;
	double		end_time;
	t_game		*game;

	game = (t_game *)data;
	if (is_bonus())
		start_time = get_time_in_seconds();
	if (game->graphics->view == 0)
		render_menu(game);
	else if (game->graphics->view == 1)
		render_game(game);
	else if (game->graphics->view == 2)
		render_inventory(game);
	if (is_bonus())
	{
		end_time = get_time_in_seconds();
		game->graphics->fps = 1.0 / (end_time - start_time);
		if (game->events->debug_enabled)
			debug_fps(game);
	}
	game->graphics->frame++;
	game->ray->frame++;
}
