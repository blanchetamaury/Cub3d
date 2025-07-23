/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:24:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/23 20:11:12 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_draw_col(t_game *game, int len, int k, int tex_x)
{
	mlx_color	raw;
	float		intensity;
	int			idx;

	while (k < game->ray->draw_end)
	{
		intensity = (2.0f + game->events->flashlight * 4.0f)
			* (1.0f - (game->ray->transform_y / game->ray->light));
		idx = ((k - game->ray->draw_start) * game->texture->battery->height
				/ game->ray->sprite_height) * game->texture->battery->width
			+ tex_x;
		raw = game->texture->battery->colors[idx];
		if (((raw.r + raw.g + raw.b) / 3) < 20 || raw.a * intensity < 255)
		{
			raw.r = 0;
			raw.g = 0;
			raw.b = 0;
		}
		else
			raw.a = raw.a * intensity;
		if (raw.a)
			mlx_set_image_pixel(game->graphics->init,
				game->img[RENDER], len, k, raw);
		k++;
	}
}

void	sprite_draw_raw(t_game *game, int len, int draw_end_x, float *z_buffer)
{
	int	draw_start_x;
	int	tex_x;

	draw_start_x = len;
	while (len < draw_end_x)
	{
		tex_x = (len - draw_start_x) * game->texture->battery->width
			/ game->ray->sprite_width;
		if (game->ray->transform_y <= 0
			|| game->ray->transform_y >= z_buffer[len])
			;
		else
			sprite_draw_col(game, len, game->ray->draw_start, tex_x);
		len++;
	}
}

static int	find_draw_start(t_game *game, int sprite_screen_x)
{
	int	draw_start_x;

	draw_start_x = -game->ray->sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	return (draw_start_x);
}

static int	find_draw_end(t_game *game, int sprite_screen_x)
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

void	raycasting_sprite(t_game *game, int status, float *z_buffer)
{
	int	len;
	int	y;
	int	x;

	len = 0;
	y = 0;
	if (game->ray->step_x < 0)
	{
		ft_stats(game->map->map, &y, &x);
		y--;
		while (y > 0 && status == 1)
		{
			if (game->map->map[y])
			{
				x = 0;
				while (game->map->map[y][x])
				{
					raycasting_sprite_condition(game, x, y, z_buffer);
					x++;
				}
			}
			y--;
		}
	}
	else if (game->ray->step_x > 0)
	{
		y = 0;
		while (game->map->map[y] && status == 1)
		{
			if (game->map->map[y])
			{
				x = ft_strlen(game->map->map[y]);
				while (x > 0)
				{
					raycasting_sprite_condition(game, x, y, z_buffer);
					x--;
				}
			}
			y++;
		}
	}
	else
	{
		while (game->map->map[y] && status == 1)
		{
			x = 0;
			while (game->map->map[y][x])
			{
				raycasting_sprite_condition(game, x, y, z_buffer);
				x++;
			}
			y++;
		}
	}
}
