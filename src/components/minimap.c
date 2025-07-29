/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:26:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/29 10:21:59 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_map_el(t_game *game, int to_draw[4], int x, int y)
{
	if (to_draw[0] == 1)
		mlx_put_image_to_window(game->graphics->init,
			game->graphics->window, game->img[MAP_R], x, y);
	if (to_draw[1] == 1)
		mlx_put_image_to_window(game->graphics->init,
			game->graphics->window, game->img[MAP_L], x, y);
	if (to_draw[2] == 1)
		mlx_put_image_to_window(game->graphics->init,
			game->graphics->window, game->img[MAP_T], x, y);
	if (to_draw[3] == 1)
		mlx_put_image_to_window(game->graphics->init,
			game->graphics->window, game->img[MAP_B], x, y);
}

static void	init_map_value(t_game *game, int *base_x, int *base_y, int *y)
{
	*base_y = (int) game->player->pos_y - 7;
	*base_x = (int) game->player->pos_x - 7;
	if (*base_y < 0)
		*base_y = 0;
	if (*base_x < 0)
		*base_x = 0;
	*y = *base_y;
}

static void	get_texture(t_game *game, int x, int y, int to_draw[4])
{
	to_draw[0] = 0;
	to_draw[1] = 0;
	to_draw[2] = 0;
	to_draw[3] = 0;
	if (game->map->map[y][x] != '1' && game->map->map[y][x] != 'Q')
		return ;
	if ((x > 0 && game->map->map[y][x] != game->map->map[y][x - 1]) || x == 0)
		to_draw[0] = 1;
	if ((game->map->map[y][x + 1] && game->map->map[y][x]
		!= game->map->map[y][x + 1]) || !game->map->map[y][x + 1])
		to_draw[1] = 1;
	if ((y > 0 && game->map->map[y][x] != game->map->map[y - 1][x]) || y == 0)
		to_draw[2] = 1;
	if ((game->map->map[y + 1] && (int)ft_strlen(game->map->map[y + 1]) >= x
			&& game->map->map[y][x] != game->map->map[y + 1][x])
		|| !game->map->map[y + 1])
		to_draw[3] = 1;
}

void	minimap(t_game *game, int pos_x, int pos_y)
{
	int		base_x;
	int		base_y;
	int		x;
	int		y;
	int		to_draw[4];

	init_map_value(game, &base_x, &base_y, &y);
	pos_y -= base_y * 32;
	pos_x -= base_x * 32;
	while (game->map->map[y] && y < base_y + 12)
	{
		x = base_x;
		while (game->map->map[y][x] && x < base_x + 14)
		{
			get_texture(game, x, y, to_draw);
			draw_map_el(game, to_draw, pos_x + x * 32,
				pos_y + y * 32);
			if (y == (int)game->player->pos_y && x == (int)game->player->pos_x)
				mlx_put_image_to_window(game->graphics->init,
					game->graphics->window, game->img[MAP_P],
					pos_x + x * 32, pos_y + y * 32);
			x++;
		}
		y++;
	}
}
