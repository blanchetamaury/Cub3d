/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_ghost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:07:09 by amaury            #+#    #+#             */
/*   Updated: 2025/07/26 13:10:50 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_color	apply_shader(mlx_color raw, float intensity)
{
	if (raw.r * intensity < 20)
		raw.r = 0;
	if (raw.g * intensity < 20)
		raw.g = 0;
	if (raw.b * intensity < 20)
		raw.b = 0;
	if (raw.r * intensity > 230)
		raw.r = 230 * (230 / raw.r);
	if (raw.g * intensity > 230)
		raw.g = 230 * (230 / raw.g);
	if (raw.b * intensity > 230)
		raw.b = 230 * (230 / raw.b);
	if (raw.r * intensity <= 230 && raw.r * intensity >= 20)
		raw.r = raw.r * intensity;
	if (raw.g * intensity <= 230 && raw.g * intensity >= 20)
		raw.g = raw.g * intensity;
	if (raw.b * intensity <= 230 && raw.b * intensity >= 20)
		raw.b = raw.b * intensity;
	return (raw);
}

void	ghost_draw_col(t_game *game, t_image *text, int k, int tex_x)
{
	mlx_color	raw;
	float		shade;
	float		intensity;
	int			idx;

	while (k < game->ray->draw_end)
	{
		game->ray->color_x = (float)k - WIDTH_WINDOW / 3 - 0;
		shade = shade_result(game->ray, game->ray->len);
		intensity = (1.0f + game->events->flashlight * 3.0f) * shade
			* (1.0f - (game->ray->transform_y / game->ray->light));
		idx = ((k - game->ray->draw_start)
				* text[get_current_ghost_texture(game)].height
				/ game->ray->sprite_height)
			* text[get_current_ghost_texture(game)].width + tex_x;
		raw = text[get_current_ghost_texture(game)].colors[idx];
		raw = apply_shader(raw, intensity);
		if (raw.a)
			mlx_set_image_pixel(game->graphics->init,
				game->img[RENDER], game->ray->len, k, raw);
		k++;
	}
}

void	ghost_draw_raw(t_game *game, t_image *text, int draw_end_x,
			float *z_buffer)
{
	int	draw_start_x;
	int	tex_x;

	draw_start_x = game->ray->len;
	while (game->ray->len < draw_end_x)
	{
		tex_x = (game->ray->len - draw_start_x)
			* text[get_current_ghost_texture(game)].width
			/ game->ray->sprite_width;
		if (game->ray->transform_y <= 0
			|| game->ray->transform_y >= z_buffer[game->ray->len])
			;
		else
			ghost_draw_col(game, text, game->ray->draw_start, tex_x);
		game->ray->len++;
	}
}

int	raycasting_ghost_calc(t_game *game, float x, float y,
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

void	raycasting_ghost(t_game *game, t_raycasting *ray, float *z_buffer)
{
	int	sprite_screen_x;
	int	i;

	i = 0;
	while (ray->count_bot > i)
	{
		sprite_screen_x = raycasting_ghost_calc(game, game->bot[i].pos_x,
				game->bot[i].pos_y, 0);
		ray->sprite_height = abs((int)(HEIGHT_WINDOW
					/ ray->transform_y)) / 3;
		ray->draw_start = -ray->sprite_height / 2 + HEIGHT_WINDOW
			/ 2 + ray->sprite_height;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->sprite_height / 2 + HEIGHT_WINDOW
			/ 2 + ray->sprite_height;
		if (ray->draw_end >= HEIGHT_WINDOW)
			ray->draw_end = HEIGHT_WINDOW - 1;
		ray->sprite_width = abs((int)(HEIGHT_WINDOW
					/ ray->transform_y)) / 3;
		ray->len = find_draw_start(game, sprite_screen_x);
		ghost_draw_raw(game, game->text, find_draw_end(game, sprite_screen_x),
			z_buffer);
		i++;
	}
}
