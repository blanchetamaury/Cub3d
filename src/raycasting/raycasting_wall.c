/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/28 10:28:03 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_wall_condition(t_game *game)
{
	if (game->ray->raylength_x < game->ray->raylength_y)
	{
		game->ray->map_x += game->ray->step_x;
		game->ray->raylength_x += game->ray->ray_x;
		return (0);
	}
	else
	{
		game->ray->map_y += game->ray->step_y;
		game->ray->raylength_y += game->ray->ray_y;
		return (1);
	}
}

static int	find_wall(t_game *game, int *status)
{
	int	side;

	side = 0;
	while (1)
	{
		if (game->map->map[game->ray->map_y][game->ray->map_x] == 'B')
			*status = 1;
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1'
			|| game->map->map[game->ray->map_y][game->ray->map_x] == 'Q')
			break ;
		side = find_wall_condition(game);
	}
	return (side);
}

int	draw_size_wall(t_game *game, int i)
{
	int		lineheight;
	float	camera_x;
	float	half_fov;
	float	angle_diff;

	camera_x = 2.0f * i / (float)WIDTH_WINDOW - 1.0f;
	half_fov = (game->ray->fov / 2) * (3.14 / 180.0f);
	angle_diff = camera_x * half_fov;
	if (game->ray->side == 0)
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

static int	raycasting_wall_print(t_game *game, int i, float *z_buffer)
{
	static mlx_color	color[HEIGHT_WINDOW * 1];
	int					count;

	count = 0;
	mlx_get_image_region(game->graphics->init, game->img[RENDER],
		i, 0, 1, HEIGHT_WINDOW, color);
	while (count < 6)
	{
		mlx_set_image_region(game->graphics->init, game->img[RENDER],
			i + count, 0, 1, HEIGHT_WINDOW, color);
		z_buffer[i + count] = game->ray->perpwalldist;
		count++;
	}
	i += count;
	return (i);
}

void	raycasting_wall(t_game *game, int *status, float *z_buffer)
{
	int		i;
	int		lineheight;

	i = 0;
	*status = 0;
	while (i < WIDTH_WINDOW)
	{
		game->ray->door = 0;
		init_calc(game->ray, game->player,
			init_angle(game->ray, game->player, i));
		init_dir(game->ray);
		game->ray->side = find_wall(game, status);
		lineheight = draw_size_wall(game, i);
		game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
		wall_size_texture(game->ray, game, game->text, lineheight);
		game->ray->len = game->ray->draw_start;
		draw_wall(game, i, game->ray);
		i = raycasting_wall_print(game, i, z_buffer);
	}
	raycasting_door(game, z_buffer);
	game->ray->frame++;
}
