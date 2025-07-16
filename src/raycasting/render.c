/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:44:55 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/15 15:54:04 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	change_view(t_game *game, int view)
{
	game->graphics->view = view;
	game->graphics->frame = 0;
}

double get_time_in_seconds(void) {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (t.tv_sec + t.tv_usec / 1000000.0);
}

void	render(void *data)
{
	double		start_time;
	double		end_time;
	t_game		*game;

	game = (t_game *)data;
	start_time = get_time_in_seconds();
	if (game->graphics->view == 0)
		render_menu(game);
	else if (game->graphics->view == 1)
		render_game(game);
	else if (game->graphics->view == 2)
		render_inventory(game);
	end_time = get_time_in_seconds();
	printf("Frame rendered in %.3f seconds (FPS: %.2f)\n", end_time - start_time,
		1.0 / (end_time - start_time));
}
