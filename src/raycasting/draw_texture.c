/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/08/06 13:22:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_wall_face_north_and_south(t_raycasting *ray, int i,
				t_image *text, t_game *game)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	shade = shade_result(ray, game->ray->len);
	if (ray->door == 1 && ray->tex_x >= 0 && ray->tex_x < text[DOOR].width
		&& ray->tex_y >= 0 && ray->tex_y < text[DOOR].height)
		tmp = text[DOOR].colors[ray->tex_y * text[DOOR].width + ray->tex_x];
	else if (ray->tex_x < text[EXIT].width && ray->tex_y >= 0 && ray->tex_y
		< text[EXIT].height && game->map->map[ray->map_y][ray->map_x] == 'Q')
		tmp = text[EXIT].colors[ray->tex_y * text[EXIT].width + ray->tex_x];
	else if (ray->step_y > 0 && ray->tex_x < text[NORTH].width && ray->tex_y
		>= 0 && ray->tex_y < text[NORTH].height)
		tmp = text[NORTH].colors[ray->tex_y * text[NORTH].width + ray->tex_x];
	else if (ray->tex_x < text[SOUTH].width && ray->tex_y >= 0
		&& ray->tex_y < text[SOUTH].height)
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
	if (ray->door == 1 && ray->tex_x >= 0 && ray->tex_x < text[DOOR].width
		&& ray->tex_y >= 0 && ray->tex_y < text[DOOR].height)
		tmp = text[DOOR].colors[ray->tex_y * text[DOOR].width + ray->tex_x];
	else if (ray->tex_x < text[EXIT].width && ray->tex_y >= 0 && ray->tex_y
		< text[EXIT].height && game->map->map[ray->map_y][ray->map_x] == 'Q')
		tmp = text[EXIT].colors[ray->tex_y * text[EXIT].width + ray->tex_x];
	else if (ray->step_x > 0 && ray->tex_x < text[WEST].width && ray->tex_y
		>= 0 && ray->tex_y < text[WEST].height)
		tmp = text[WEST].colors[ray->tex_y * text[WEST].width + ray->tex_x];
	else if (ray->tex_x < text[EAST].width && ray->tex_y >= 0
		&& ray->tex_y < text[EAST].height)
		tmp = text[EAST].colors[ray->tex_y * text[EAST].width + ray->tex_x];
	color_alpha = 1.0f - (ray->perpwalldist / ray->light);
	if (is_bonus())
		tmp = texture_shader(tmp, (shade * game->ray->light)
				/ (2 + game->events->flashlight * 4) * color_alpha);
	mlx_set_image_pixel(game->graphics->init, game->img[RENDER],
		i, game->ray->len, tmp);
}

void	draw_door(t_game *game, int i, t_raycasting *ray)
{
	if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'M')
		ray->tex_pos += ray->frame * 2;
	else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'C')
		ray->tex_pos += 110 - (ray->frame * 2);
	else if (ray->door && game->map->map[ray->map_y][ray->map_x] == 'O')
		ray->tex_pos = 110;
	while (game->ray->len < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (game->text[DOOR].height - 1);
		ray->tex_pos += ray->tex_step;
		if (!ray->side)
			draw_wall_face_west_and_east(game->ray, i, game->text, game);
		else
			draw_wall_face_north_and_south(game->ray, i, game->text, game);
		game->ray->len++;
	}
}

void	draw_wall(t_game *game, int i, t_raycasting *ray)
{
	if (ray->door)
	{
		draw_door(game, i, ray);
	}
	else
	{
		while (game->ray->len < ray->draw_end)
		{
			if (game->map->map[ray->map_y][ray->map_x] == '1')
				ray->tex_y = (int)ray->tex_pos
					& (get_face_height(ray, game->text) - 1);
			else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
				ray->tex_y = (int)ray->tex_pos & (game->text[EXIT].height - 1);
			ray->tex_pos += ray->tex_step;
			if (ray->door)
				ray->tex_y = (int)ray->tex_pos & (game->text[DOOR].height - 1);
			if (!ray->side)
				draw_wall_face_west_and_east(game->ray, i, game->text, game);
			else
				draw_wall_face_north_and_south(game->ray, i, game->text, game);
			game->ray->len++;
		}
	}
}
