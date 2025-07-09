/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 11:15:58 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float	init_angle(t_game *game, int i)
{
	float	deltaAngle;
	float	rayAngle;
	float	deg_to_rad;

	deg_to_rad = 3.14 / 180.0f;
	deltaAngle = FOV / (float)width_window;
	rayAngle = (game->player->angle - FOV / 2) + i * deltaAngle;
	return (rayAngle * deg_to_rad);
}

static void	init_calc(t_game *game, float rad)
{
	game->ray->map_x = (int)game->player->pos_x;
	game->ray->map_y = (int)game->player->pos_y;
	game->ray->cos_x = cos(rad);
	game->ray->sin_y = sin(rad);
	game->ray->ray_x = sqrt(1 + (game->ray->sin_y / game->ray->cos_x) * (game->ray->sin_y / game->ray->cos_x));
	game->ray->ray_y = sqrt(1 + (game->ray->cos_x / game->ray->sin_y) * (game->ray->cos_x / game->ray->sin_y));
	game->ray->rofract_x = game->player->pos_x - (int)game->player->pos_x;
	game->ray->rofract_y = game->player->pos_y - (int)game->player->pos_y;
}

static void	init_dir(t_game *game)
{
	if (game->ray->cos_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->raylength_x = game->ray->rofract_x * game->ray->ray_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->raylength_x = (1 - game->ray->rofract_x) * game->ray->ray_x;
	}
	if (game->ray->sin_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->raylength_y = game->ray->rofract_y * game->ray->ray_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->raylength_y = (1 - game->ray->rofract_y) * game->ray->ray_y;
	}
}

static int	find_wall(t_game *game)
{
	int	j;
	int side;
	int hit;
	mlx_color	vision;

	j = 0;
	side = 0;
	hit = 0;
	while (hit == 0)
	{
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1')
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
		draw_rectangle_mlx(game, (game->ray->map_x * 20), (game->ray->map_y* 20), 20, 20, vision);
		if (game->ray->raylength_x < game->ray->raylength_y)
		{
			game->ray->map_x += game->ray->step_x;
			game->ray->raylength_x += game->ray->ray_x;
			side = 0;
		}
		else
		{
			game->ray->map_y += game->ray->step_y;
			game->ray->raylength_y += game->ray->ray_y;
			side = 1;
		}
		j++;
	}
	return (side);
}

void    raycasting(t_game *game)
{
	float	rad;
	float	perpwalldist;
	int		i;
	int		lineheight;
	int		side;
	int		draw_start;
	int		draw_end;
	int		len;

	i = 0;
	while (i < width_window)
	{
		
		rad = init_angle(game, i);
		init_calc(game, rad);
		init_dir(game);
		side = find_wall(game);
		
		if (side == 0)
			perpwalldist = (game->ray->raylength_x - game->ray->ray_x);
		else
			perpwalldist = (game->ray->raylength_y - game->ray->ray_y);
		if (perpwalldist == 0)
			perpwalldist = 1;
		lineheight = (int)(height_window / perpwalldist);
		draw_start = -lineheight / 2 + height_window /2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + height_window /2;
		if (draw_end >= height_window)
			draw_end = height_window - 1;
		mlx_color tmp;
		len = 0;
		while (len < draw_start) // sky
		{
			tmp.rgba = 0x0000FFFF;
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
			mlx_set_image_pixel(game->graphics->init, game->map->img, i, len, tmp);
			len++;
		}
		while (len < height_window) // ground
		{
			tmp.rgba = 0xFF0000FF;
			mlx_set_image_pixel(game->graphics->init, game->map->img, i, len, tmp);
			len++;
		}
		i++;
	}
}
