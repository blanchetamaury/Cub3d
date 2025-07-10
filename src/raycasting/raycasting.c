/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/10 16:48:32 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	draw_size_wall(t_game *game, int side)
{
	int		lineheight;

	if (side == 0)
		game->ray->perpwalldist = (game->ray->raylength_x - game->ray->ray_x);
	else
		game->ray->perpwalldist = (game->ray->raylength_y - game->ray->ray_y);
	if (game->ray->perpwalldist == 0)
		game->ray->perpwalldist = 1;
	lineheight = (int)(height_window / game->ray->perpwalldist);
	game->ray->draw_start = -lineheight / 2 + height_window / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = lineheight / 2 + height_window / 2;
	if (game->ray->draw_end >= height_window)
		game->ray->draw_end = height_window - 1;
	return (lineheight);
}

void	raycasting(t_game *game)
{
	int		i;
	int		side;
	int		lineheight;

	i = 0;
	while (i < width_window)
	{
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game);
		lineheight = draw_size_wall(game, side);
		game->ray->color_x = (float)i - width_window / 3 - 60;
		draw_sky(game, i);
		wall_size_texture(game, side, lineheight);
		draw_wall(game, game->ray->draw_start, side, i);
		draw_ground(game, game->ray->draw_end, i);
		i++;
	}
}
