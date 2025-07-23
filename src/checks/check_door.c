/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:54:04 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 11:10:07 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_valid_door(t_game *game, int x, int y)
{
	if (y < 0 || !game->map->map[y + 1] || x < 0)
		return (0);
	if (game->map->map[y - 1][x] == '1' && game->map->map[y + 1][x] == '1')
		return (1);
	if (game->map->map[y][x - 1] == '1' && game->map->map[y][x + 1] == '1')
		return (1);
	return (0);
}

int	check_door(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'P')
			{
				if (is_valid_door(game, x, y) == 0)
				{
					log_warn("Invalid door found. Ensure that is "
						"surrounded by walls. Removing it.");
					game->map->map[y][x] = 'O';
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}