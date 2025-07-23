/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/23 09:46:30 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_wall_condition(t_game *game)
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
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1')
			break ;
		side = find_wall_condition(game);
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

static int check_door_hit(t_game *g, int side, int *status, float wall_dist)
{
    float t;
    float plane;

    if (side == 0)
	{
        if (g->ray->cos_x == 0)
			return 0;
        plane = g->ray->map_x + 0.5f;
        t = (plane - g->player->pos_x) / g->ray->cos_x;
    }
	else
	{
        if (g->ray->sin_y == 0)
			return 0;
        plane = g->ray->map_y + 0.5f;
        t = (plane - g->player->pos_y) / g->ray->sin_y;
    }
    if (t > 0.0f && t < wall_dist)
	{
        g->ray->perpwalldist = t;
        g->ray->door = 1;
        *status = 1;
        return 1;
    }
    return 0;
}

static int find_door(t_game *g, int *status, float wall_dist)
{
    int side = 0;

    while (1)
    {
        if (g->map->map[g->ray->map_y][g->ray->map_x] == 'P')
            if (check_door_hit(g, side, status, wall_dist))
                return side;

        if (g->map->map[g->ray->map_y][g->ray->map_x] == '1')
            break;
        side = find_wall_condition(g);
    }
    return side;
}

int draw_size_wall_forced(t_game *g, int i)
{
    int lineheight;
    float camera_x = 2.0f * i / (float)WIDTH_WINDOW - 1.0f;
    float half_fov = (g->ray->fov / 2) * (3.14f / 180.0f);
    float angle_diff = camera_x * half_fov;

    if (g->ray->perpwalldist == 0) g->ray->perpwalldist = 0.0001f;
    float dist = g->ray->perpwalldist * cosf(angle_diff);
    lineheight = (int)(HEIGHT_WINDOW / dist);
    g->ray->draw_start = -lineheight / 2 + HEIGHT_WINDOW / 2;
    if (g->ray->draw_start < 0) g->ray->draw_start = 0;
    g->ray->draw_end = lineheight / 2 + HEIGHT_WINDOW / 2;
    if (g->ray->draw_end >= HEIGHT_WINDOW) g->ray->draw_end = HEIGHT_WINDOW - 1;
    return lineheight;
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
		game->ray->door = 0;
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game, status);
		lineheight = draw_size_wall(game, side, i);
		game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
		wall_size_texture(game, side, lineheight);
		draw_wall(game, game->ray->draw_start, side, i);
		i = raycasting_wall_print(game, i, z_buffer);
	}
	i = 0;
	int	s;
	while (i < WIDTH_WINDOW)
	{
		s = 0;
		game->ray->door = 0;
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_door(game, &s, z_buffer[i]);
		if (s == 1)
		{
			lineheight = draw_size_wall_forced(game, i);
			game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
			wall_size_texture(game, side, lineheight);
			draw_wall(game, game->ray->draw_start, side, i);
		}
		i++;
	}
	game->ray->frame++;
}
