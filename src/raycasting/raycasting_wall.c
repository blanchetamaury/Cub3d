/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 10:42:51 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_wall(t_game *game)
{
	int	j;
	int	side;

	j = 0;
	side = 0;
	while (1)
	{
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1')
			break ;
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

int	draw_size_wall(t_game *game, int side, int i)
{
	int		lineheight;
	float	camera_x;
	float	half_fov;
	float	angle_diff;

	camera_x = 2.0f * i / (float)WIDTH_WINDOW - 1.0f;
	half_fov = (3.14 / 180.0f) / 2.0f;
	angle_diff = camera_x * half_fov;
	if (side == 0)
		game->ray->perpwalldist = (game->ray->raylength_x - game->ray->ray_x)
			* cosf(angle_diff);
	else
		game->ray->perpwalldist = (game->ray->raylength_y - game->ray->ray_y)
			* cosf(angle_diff);
	if (game->ray->perpwalldist == 0)
		game->ray->perpwalldist = 1 * cosf(angle_diff);
	lineheight = (int)(HEIGHT_WINDOW / game->ray->perpwalldist);
	game->ray->draw_start = -lineheight / 2 + HEIGHT_WINDOW / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = lineheight / 2 + HEIGHT_WINDOW / 2;
	if (game->ray->draw_end >= HEIGHT_WINDOW)
		game->ray->draw_end = HEIGHT_WINDOW - 1;
	return (lineheight);
}

void	raycasting_wall(t_game *game)
{
	int		i;
	int		side;
	int		lineheight;
	int		count;
	mlx_color	color[HEIGHT_WINDOW * 1];

	i = 0;
	while (i < WIDTH_WINDOW)
	{
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game);
		lineheight = draw_size_wall(game, side, i);
		game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
		wall_size_texture(game, side, lineheight);
		draw_wall(game, game->ray->draw_start, side, i);
		count = 0;
		mlx_get_image_region(game->graphics->init, game->texture->render, i, 0, 1, HEIGHT_WINDOW, color);
		while (count < 6)
		{
			mlx_set_image_region(game->graphics->init, game->texture->render, i + count, 0, 1, HEIGHT_WINDOW, color);
			count++;
		}
		i += count;
	}
}
