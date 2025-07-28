/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:22:54 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/28 10:48:55 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_door_condition(t_game *g, int i, int side)
{
	float	lineheight;

	if (g->map->map[g->ray->map_y][g->ray->map_x] == 'O')
	{
		lineheight = draw_size_wall_forced(g, i);
		g->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
		g->ray->side = side;
		g->ray->len = g->ray->draw_start;
		wall_size_texture(g->ray, g, g->text, lineheight);
		draw_wall(g, i, g->ray);
		return (-1);
	}
	else
		return (side);
}

static int	check_door_hit(t_game *g, int side, int *status, float wall_dist)
{
	float	t;
	float	plane;

	if (side == 0)
	{
		if (g->ray->cos_x == 0)
			return (0);
		plane = g->ray->map_x + 0.5f;
		t = (plane - g->player->pos_x) / g->ray->cos_x;
	}
	else
	{
		if (g->ray->sin_y == 0)
			return (0);
		plane = g->ray->map_y + 0.5f;
		t = (plane - g->player->pos_y) / g->ray->sin_y;
	}
	if (t > 0.0f && t < wall_dist)
	{
		g->ray->perpwalldist = t;
		g->ray->door = 1;
		*status = 1;
		return (1);
	}
	return (0);
}

static int	find_door(t_game *g, int *status, float wall_dist, int i)
{
	int		side;

	side = 0;
	while (1)
	{
		if (g->map->map[g->ray->map_y][g->ray->map_x] == 'P'
			|| g->map->map[g->ray->map_y][g->ray->map_x] == 'C'
			|| g->map->map[g->ray->map_y][g->ray->map_x] == 'M'
			|| g->map->map[g->ray->map_y][g->ray->map_x] == 'O')
		{
			if (check_door_hit(g, side, status, wall_dist))
				return (find_door_condition(g, i, side));
		}
		if (g->map->map[g->ray->map_y][g->ray->map_x] == '1'
			|| g->map->map[g->ray->map_y][g->ray->map_x] == 'Q')
			break ;
		side = find_wall_condition(g);
	}
	return (side);
}

void	raycasting_door(t_game *game, float *z_buffer)
{
	int		s;
	int		i;
	int		lineheight;

	i = 0;
	while (i < WIDTH_WINDOW)
	{
		s = 0;
		game->ray->door = 0;
		init_calc(game->ray, game->player,
			init_angle(game->ray, game->player, i));
		init_dir(game->ray);
		game->ray->side = find_door(game, &s, z_buffer[i], i);
		if (s == 1 && game->ray->side != -1)
		{
			lineheight = draw_size_wall_forced(game, i);
			game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
			wall_size_texture(game->ray, game, game->text, lineheight);
			game->ray->len = game->ray->draw_start;
			draw_wall(game, i, game->ray);
			z_buffer[i] = game->ray->perpwalldist;
		}
		i++;
	}
}
