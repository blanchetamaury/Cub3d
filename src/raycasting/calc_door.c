/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:48:18 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/28 10:49:34 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_size_wal_forced_utils(t_game *g, int lineheight)
{
	if (g->map->map[g->ray->map_y][g->ray->map_x] == 'M')
	{
		g->ray->draw_end = lineheight * (0.5f - g->ray->frame / 60.0f)
			+ HEIGHT_WINDOW / 2;
		if ((0.5f - g->ray->frame / 60.0f) <= -0.4f)
			g->map->map[g->ray->map_y][g->ray->map_x] = 'O';
	}
	else if (g->map->map[g->ray->map_y][g->ray->map_x] == 'C')
	{
		g->ray->draw_end = lineheight * (-0.4f + g->ray->frame / 60.0f)
			+ HEIGHT_WINDOW / 2;
		if ((-0.4f + g->ray->frame / 60.0f) >= 0.5f)
			g->map->map[g->ray->map_y][g->ray->map_x] = 'P';
	}
	else if (g->map->map[g->ray->map_y][g->ray->map_x] == 'O')
		g->ray->draw_end = lineheight * -0.4f + HEIGHT_WINDOW / 2;
	else
		g->ray->draw_end = lineheight / 2 + HEIGHT_WINDOW / 2;
}

int	draw_size_wall_forced(t_game *g, int i)
{
	int		lineheight;
	float	camera_x;
	float	half_fov;
	float	angle_diff;
	float	dist;

	camera_x = 2.0f * i / (float)WIDTH_WINDOW - 1.0f;
	half_fov = (g->ray->fov / 2) * (3.14f / 180.0f);
	angle_diff = camera_x * half_fov;
	if (g->ray->perpwalldist == 0)
		g->ray->perpwalldist = 0.0001f;
	dist = g->ray->perpwalldist * cosf(angle_diff);
	lineheight = (int)(HEIGHT_WINDOW / dist);
	g->ray->draw_start = -lineheight / 2 + HEIGHT_WINDOW / 2;
	if (g->ray->draw_start < 0)
		g->ray->draw_start = 0;
	draw_size_wal_forced_utils(g, lineheight);
	if (g->ray->draw_end >= HEIGHT_WINDOW)
		g->ray->draw_end = HEIGHT_WINDOW - 1;
	return (lineheight);
}
