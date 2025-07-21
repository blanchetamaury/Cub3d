/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/21 13:43:41 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_wall_condition(t_game *game, int *map_x, int *map_y)
{
	if (game->ray->raylength_x < game->ray->raylength_y)
	{
		game->ray->map_x += game->ray->step_x;
		game->ray->raylength_x += game->ray->ray_x;
		*map_x += game->ray->step_x + 0.95;
		return (0);
	}
	else
	{
		game->ray->map_y += game->ray->step_y;
		game->ray->raylength_y += game->ray->ray_y;
		*map_y += game->ray->step_y + 0.95;
		return (1);
	}
}

static int	find_wall(t_game *game, int *status)
{
	int	side;
	int	map_x;
	int	map_y;

	side = 0;
	map_x = game->ray->map_x;
	map_y = game->ray->map_y;
	while (1)
	{
		if (game->map->map[map_y][map_x] == 'B')
			*status = 1;
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1')
			break ;
		side = find_wall_condition(game, &map_x, &map_y);
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
	half_fov = (game->ray->fov / 2) * (3.14 / 180.0f);
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

static int	raycasting_wall_print(t_game *game, int i, float *z_buffer)
{
	static mlx_color	color[HEIGHT_WINDOW * 1];
	int					count;

	count = 0;
	mlx_get_image_region(game->graphics->init, game->texture->render,
		i, 0, 1, HEIGHT_WINDOW, color);
	while (count < 6)
	{
		mlx_set_image_region(game->graphics->init, game->texture->render,
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
	int		side;
	int		lineheight;

	i = 0;
	*status = 0;
	while (i < WIDTH_WINDOW)
	{
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game, status);
		if (game->ray->map_x - game->player->pos_x < 9 && game->ray->map_x
			- game->player->pos_x > -9 && game->ray->map_y
			- game->player->pos_y < 9 && game->ray->map_y
			- game->player->pos_y > -9)
		{
			lineheight = draw_size_wall(game, side, i);
			game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
			wall_size_texture(game, side, lineheight);
			draw_wall(game, game->ray->draw_start, side, i);
			i = raycasting_wall_print(game, i, z_buffer);
		}
		else
			z_buffer[i++] = game->ray->perpwalldist;
	}
}
