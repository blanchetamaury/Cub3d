/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 10:20:14 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    raycasting(t_game *game)
{
    	float	cos_x;
	float	sin_y;
	float	ray_x;
	float	ray_y;
	float	raylength_x;
	float	raylength_y;
	float	rofract_x;
	float	rofract_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		i;
	int		draw_start;
	int		draw_end;
	mlx_color	vision;

	const float DEG2RAD = 3.14 / 180.0f;
	i = 0;
	while (i < width_window)
	{
		float deltaAngle = FOV / (float)width_window;
		float rayAngle = (game->player->angle - FOV / 2) + i * deltaAngle;
		float rad = rayAngle * DEG2RAD;
		map_x = (int)game->player->pos_x;
		map_y = (int)game->player->pos_y;
		cos_x = cos(rad);
		sin_y = sin(rad);

		ray_x = sqrt(1 + (sin_y / cos_x) * (sin_y / cos_x));
		ray_y = sqrt(1 + (cos_x / sin_y) * (cos_x / sin_y));
		rofract_x = game->player->pos_x - (int)game->player->pos_x;
		rofract_y = game->player->pos_y - (int)game->player->pos_y;
		if (cos_x < 0)
		{
			step_x = -1;
			raylength_x = rofract_x * ray_x;
		}
		else
		{
			step_x = 1;
			raylength_x = (1 - rofract_x) * ray_x;
		}
		if (sin_y < 0)
		{
			step_y = -1;
			raylength_y = rofract_y * ray_y;
		}
		else
		{
			step_y = 1;
			raylength_y = (1 - rofract_y) * ray_y;
		}
		int hit;
		int j;
		int side;
		hit = 0;
		j = 0;
		while (hit == 0)
		{
			if (game->map->map[map_y][map_x] == '1')
			{
				hit = 1;
				break ;
			}
			if (255 - j * 20 < 0) {
				hit = 1;
				vision.a = 0;
			}
			else
				vision.a = 255 - j * 20;
			vision.b = 255;
			vision.g = 0;
			vision.r = 0;
			//draw_rectangle_mlx(game, (map_x * 20), (map_y* 20), 20, 20, vision);
			if (raylength_x < raylength_y)
			{
				map_x += step_x;
				raylength_x += ray_x;
				side = 0;
			}
			else
			{
				map_y += step_y;
				raylength_y += ray_y;
				side = 1;
			}
			j++;
		}
		float perpwalldist;
		if (side == 0)
			perpwalldist = (raylength_x - ray_x);
		else
			perpwalldist = (raylength_y - ray_y);
		int lineheight;
		
		//float cameraOffset = (game->player->angle - rayAngle) * DEG2RAD;
		//float correctedDist = perpwalldist * cosf(cameraOffset);
		if (perpwalldist == 0)
			perpwalldist = 1;
		lineheight = (int)(height_window / perpwalldist);
		draw_start = -lineheight / 2 + height_window /2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + height_window /2;
		if (draw_end >= height_window)
			draw_end = height_window - 1;
		int len;
		mlx_color tmp;
		len = 0;
		while (len < draw_start) // sky
		{
			tmp.rgba = 0x0000FFFF;
			//mlx_pixel_put(game->graphics->init, game->graphics->window, i, len, game->texture->sky->color);
			mlx_set_image_pixel(game->graphics->init, game->map->img, i, len, tmp);
			len++;
		}
		len = draw_start;
		while (len < draw_end) // wall
		{
			if (len < draw_start + 10)
				tmp.rgba = 0xAA00AAFF;
			else if (len + 10 > draw_end)
				tmp.rgba = 0xFFFF00FF;
			else
				tmp.rgba = 0x00FF00FF;
			//if (side == 1)
			//mlx_pixel_put(game->graphics->init, game->graphics->window, i, len, tmp);
			mlx_set_image_pixel(game->graphics->init, game->map->img, i, len, tmp);
			len++;
		}
		while (len < height_window) // ground
		{
			tmp.rgba = 0xFF0000FF;
			//mlx_pixel_put(game->graphics->init, game->graphics->window, i, len, game->texture->ground->color);
			mlx_set_image_pixel(game->graphics->init, game->map->img, i, len, tmp);
			len++;
		}
		i++;
	}
}