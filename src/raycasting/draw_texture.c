/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/27 12:04:30 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_color	texture_shader(mlx_color tmp, float shade)
{
	if ((int)tmp.r * shade <= 20)
		tmp.r = 0;
	else if ((int)tmp.r * shade > 230)
		tmp.r = 230;
	else
		tmp.r = (int)tmp.r * shade;
	if ((int)tmp.g * shade <= 20)
		tmp.g = 0;
	else if ((int)tmp.g * shade > 230)
		tmp.g = 230;
	else
		tmp.g = (int)tmp.g * shade;
	if ((int)tmp.b * shade <= 20)
		tmp.b = 0;
	else if ((int)tmp.b * shade >= 230)
		tmp.b = 230;
	else
		tmp.b = (int)tmp.b * shade;
	return (tmp);
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
	else if (ray->step_y < 0)
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
	else if (ray->step_x < 0)
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
		ray->tex_y = (int)ray->tex_pos & (get_face_height(ray, game->text) - 1);
		if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'M')
			ray->tex_y += ray->frame * 2;
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'C')
			ray->tex_y += 110 - (ray->frame * 2);
		else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'O')
			ray->tex_y = 110;
		else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
			ray->tex_y = (int)ray->tex_pos & (128 - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side)
			draw_wall_face_west_and_east(game->ray, i, game->text, game);
		else
			draw_wall_face_north_and_south(game->ray, i, game->text, game);
		game->ray->len++;
	}
}
