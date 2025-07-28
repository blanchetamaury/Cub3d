/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:43:07 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/27 12:03:52 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	init_angle(t_raycasting *ray, t_player *player, int i)
{
	float	rayangle;

	rayangle = (player->angle - ray->fov / 2) + i * ray->deltaangle;
	return (rayangle * ray->deg_to_rad);
}

void	init_calc(t_raycasting *ray, t_player *player, float rad)
{
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->cos_x = cos(rad);
	ray->sin_y = sin(rad);
	ray->ray_x = sqrt(1 + (ray->sin_y / ray->cos_x)
			* (ray->sin_y / ray->cos_x));
	ray->ray_y = sqrt(1 + (ray->cos_x / ray->sin_y)
			* (ray->cos_x / ray->sin_y));
	ray->rofract_x = player->pos_x - (int)player->pos_x;
	ray->rofract_y = player->pos_y - (int)player->pos_y;
}

void	init_dir(t_raycasting *ray)
{
	if (ray->cos_x < 0)
	{
		ray->step_x = -1;
		ray->raylength_x = ray->rofract_x * ray->ray_x;
	}
	else
	{
		ray->step_x = 1;
		ray->raylength_x = (1 - ray->rofract_x) * ray->ray_x;
	}
	if (ray->sin_y < 0)
	{
		ray->step_y = -1;
		ray->raylength_y = ray->rofract_y * ray->ray_y;
	}
	else
	{
		ray->step_y = 1;
		ray->raylength_y = (1 - ray->rofract_y) * ray->ray_y;
	}
}

float	shade_result(t_raycasting *ray, int len)
{
	float	dist;
	float	max_rad;
	float	result;

	ray->color_y = (float)len - (HEIGHT_WINDOW - HEIGHT_WINDOW / 3);
	dist = hypotf(ray->color_x, ray->color_y) / (ray->light * 0.125);
	max_rad = hypotf(WIDTH_WINDOW / 2, ray->draw_start);
	result = 1.0f - (dist / max_rad);
	if (result < 0)
		result = 0;
	if (result > 1)
		result = 1.0;
	return (result);
}

void	wall_size_texture(t_raycasting *ray, t_game *game,
			t_image *text, int lineheight)
{
	if (game->ray->side == 0)
		ray->wall_x = game->player->pos_y + ray->perpwalldist * ray->sin_y;
	else
		ray->wall_x = game->player->pos_x + ray->perpwalldist * ray->cos_x;
	ray->wall_x -= floorf(ray->wall_x);
	if (ray->door == 1)
		ray->tex_x = (int)(ray->wall_x * text[DOOR].width);
	else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
		ray->tex_x = (int)(ray->wall_x * text[EXIT].width);
	else
		ray->tex_x = (int)(ray->wall_x * (float)get_face_width(ray, text));
	if (((ray->side == 0 && ray->cos_x > 0)
			|| (ray->side == 1 && ray->sin_y < 0)) && ray->door == 1)
		ray->tex_x = text[DOOR].width - ray->tex_x - 1;
	else if ((ray->side == 0 && ray->cos_x > 0)
		|| (ray->side == 1 && ray->sin_y < 0))
		ray->tex_x = get_face_width(ray, text) - ray->tex_x - 1;
	if (ray->door == 1)
		ray->tex_step = 1.0f * text[DOOR].height / lineheight;
	else if (game->map->map[ray->map_y][ray->map_x] == 'Q')
		ray->tex_step = 1.0f * text[EXIT].height / lineheight;
	else
		ray->tex_step = 1.0f * get_face_height(ray, text) / lineheight;
	ray->tex_pos = (ray->draw_start - HEIGHT_WINDOW / 2 + lineheight / 2)
		* ray->tex_step;
}
