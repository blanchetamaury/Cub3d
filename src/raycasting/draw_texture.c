/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/08/01 15:36:21 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sprite_draw_col(t_game *game, t_image *text, int len, int tex_x)
{
	mlx_color	raw;
	float		shade;
	float		intensity;
	int			k;

	k = game->ray->draw_start;
	while (k < game->ray->draw_end)
	{
		game->ray->color_x = (float)k - WIDTH_WINDOW / 3 - 0;
		shade = shade_result(game->ray, len);
		intensity = (1.0f + game->events->flashlight * 3.0f) * shade
			* (1.0f - (game->ray->transform_y / game->ray->light));
		raw = text[BATTERY].colors[((k - game->ray->draw_start)
				* text[BATTERY].height / game->ray->sprite_height)
			* text[BATTERY].width + tex_x];
		raw = sprite_intensity(raw, intensity);
		if (raw.a)
			mlx_set_image_pixel(game->graphics->init,
				game->img[RENDER], len, k, raw);
		k++;
	}
}

void	sprite_draw_raw(t_game *game, int len, int draw_end_x, float *z_buffer)
{
	t_image	*text;
	int		draw_start_x;
	int		tex_x;

	text = game->text;
	draw_start_x = len;
	while (len < draw_end_x)
	{
		tex_x = (len - draw_start_x) * text[BATTERY].width
			/ game->ray->sprite_width;
		if (game->ray->transform_y <= 0
			|| game->ray->transform_y >= z_buffer[len])
			;
		else
			sprite_draw_col(game, text, len, tex_x);
		len++;
	}
}

static void	draw_wall_face_north_and_south(t_raycasting *ray, int i,
				t_image *text, t_game *game)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	shade = shade_result(ray, game->ray->len);
	if (ray->door == 1)
		tmp = text[DOOR].colors[ray->tex_y * text[DOOR].width + ray->tex_x];
	else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
		tmp = text[EXIT].colors[ray->tex_y * text[EXIT].width + ray->tex_x];
	else if (ray->step_y > 0)
		tmp = text[NORTH].colors[ray->tex_y * text[NORTH].width + ray->tex_x];
	else
		tmp = text[SOUTH].colors[ray->tex_y * text[SOUTH].width + ray->tex_x];
	color_alpha = 1.0f - (ray->perpwalldist / ray->light);
	if (is_bonus())
		tmp = texture_shader(tmp, (shade * game->ray->light)
				/ (2 + game->events->flashlight * 4) * color_alpha);
	mlx_set_image_pixel(game->graphics->init, game->img[RENDER],
		i, game->ray->len, tmp);
}

static void	draw_wall_face_west_and_east(t_raycasting *ray, int i,
				t_image *text, t_game *game)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	shade = shade_result(ray, game->ray->len);
	if (ray->door == 1)
		tmp = text[DOOR].colors[ray->tex_y * text[DOOR].width + ray->tex_x];
	else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
		tmp = text[EXIT].colors[ray->tex_y * text[EXIT].width + ray->tex_x];
	else if (ray->step_x > 0)
		tmp = text[WEST].colors[ray->tex_y * text[WEST].width + ray->tex_x];
	else
		tmp = text[EAST].colors[ray->tex_y * text[EAST].width + ray->tex_x];
	color_alpha = 1.0f - (ray->perpwalldist / ray->light);
	if (is_bonus())
		tmp = texture_shader(tmp, (shade * game->ray->light)
				/ (2 + game->events->flashlight * 4) * color_alpha);
	mlx_set_image_pixel(game->graphics->init, game->img[RENDER],
		i, game->ray->len, tmp);
}

void	draw_wall(t_game *game, int i, t_raycasting *ray)
{
	while (game->ray->len < ray->draw_end)
	{
		if (game->map->map[ray->map_y][ray->map_x] == '1')
			ray->tex_y = (int)ray->tex_pos & (get_face_height(ray, game->text) - 1);
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'P')
			ray->tex_y = (int)ray->tex_pos & (game->text[DOOR].height - 1);
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'M')
			ray->tex_y += ray->frame * 2;
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'C')
			ray->tex_y += 110 - (ray->frame * 2);
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'O')
			ray->tex_y = 110;
		else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
			ray->tex_y = (int)ray->tex_pos & (game->text[EXIT].height - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side)
			draw_wall_face_west_and_east(game->ray, i, game->text, game);
		else
			draw_wall_face_north_and_south(game->ray, i, game->text, game);
		game->ray->len++;
	}
}
