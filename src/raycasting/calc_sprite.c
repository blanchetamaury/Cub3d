/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:46:24 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/28 10:47:11 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_draw_start(t_game *game, int sprite_screen_x)
{
	int	draw_start_x;

	draw_start_x = -game->ray->sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	return (draw_start_x);
}

int	find_draw_end(t_game *game, int sprite_screen_x)
{
	int	draw_end_x;

	draw_end_x = game->ray->sprite_width / 2 + sprite_screen_x;
	if (draw_end_x >= WIDTH_WINDOW)
		draw_end_x = WIDTH_WINDOW - 1;
	return (draw_end_x);
}

static int	raycasting_sprite_calc(t_game *game, int x, int y,
				float tan_half_fov)
{
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	invdet;

	dir_x = 0;
	dir_y = 0;
	init_rad_floor(game, &dir_x, &dir_y);
	tan_half_fov = tanf((game->ray->fov / 2) * (3.14 / 180.0f));
	plane_x = -dir_y * tan_half_fov;
	plane_y = dir_x * tan_half_fov;
	invdet = 1.0f / (plane_x * dir_y - dir_x * plane_y);
	game->ray->transform_x = invdet * (dir_y * (x - game->player->pos_x + 0.5)
			- dir_x * (y - game->player->pos_y + 0.5));
	game->ray->transform_y = invdet * (0 - plane_y
			* (x - game->player->pos_x + 0.5)
			+ plane_x * (y - game->player->pos_y + 0.5));
	return ((int)WIDTH_WINDOW / 2 * (1 + game->ray->transform_x
			/ game->ray->transform_y));
}

void	raycasting_sprite_condition(t_game *game, int x, int y, float *z_buffer)
{
	int	sprite_screen_x;

	if (game->map->map[y][x] == 'B')
	{
		sprite_screen_x = raycasting_sprite_calc(game, x, y, 0);
		game->ray->sprite_height = abs((int)(HEIGHT_WINDOW
					/ game->ray->transform_y)) / 3;
		game->ray->draw_start = -game->ray->sprite_height / 2 + HEIGHT_WINDOW
			/ 2 + game->ray->sprite_height;
		if (game->ray->draw_start < 0)
			game->ray->draw_start = 0;
		game->ray->draw_end = game->ray->sprite_height / 2 + HEIGHT_WINDOW
			/ 2 + game->ray->sprite_height;
		if (game->ray->draw_end >= HEIGHT_WINDOW)
			game->ray->draw_end = HEIGHT_WINDOW - 1;
		game->ray->sprite_width = abs((int)(HEIGHT_WINDOW
					/ game->ray->transform_y)) / 3;
		sprite_draw_raw(game, find_draw_start(game, sprite_screen_x),
			find_draw_end(game, sprite_screen_x), z_buffer);
	}
}
