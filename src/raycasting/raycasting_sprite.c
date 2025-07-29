/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:24:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/29 16:57:36 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	raycasting_loop_part_two(t_game *game, int status, float *z_buffer, int y)
{
	int	x;

	x = 0;
	if (game->ray->step_x < 0)
	{
		ft_stats(game->map->map, &y, &x);
		y--;
		while (y > 0 && status == 1)
		{
			x = 0;
			if (game->map->map[y])
				while (game->map->map[y][x])
					raycasting_sprite_condition(game, x++, y, z_buffer);
			y--;
		}
	}
	else
		return (0);
	return (1);
}

int	raycasting_sprite_loop(t_game *game, int status, float *z_buffer, int y)
{
	int	x;

	if (raycasting_loop_part_two(game, status, z_buffer, y) == 0
		&& game->ray->step_x > 0)
	{
		y = -1;
		while (game->map->map[++y] && status == 1)
		{
			x = ft_strlen(game->map->map[y]);
			while (x > 0)
				raycasting_sprite_condition(game, x--, y, z_buffer);
		}
	}
	else
		return (0);
	return (1);
}

void	raycasting_sprite(t_game *game, int status, float *z_buffer)
{
	int	y;
	int	x;

	y = 0;
	if (raycasting_sprite_loop(game, status, z_buffer, 0) == 0)
	{
		while (game->map->map[y] && status == 1)
		{
			x = 0;
			while (game->map->map[y][x])
			{
				raycasting_sprite_condition(game, x, y, z_buffer);
				x++;
			}
			y++;
		}
	}
}
