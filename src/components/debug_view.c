/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:37:31 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 09:05:30 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_map_width(t_map *map)
{
	int	w;
	int	x;
	int y;

	w = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		if ((int)ft_strlen(map->map[y]) > w)
			w = ft_strlen(map->map[y]);
		y++;
	}
	return (w);
}

static int	get_map_height(t_map *map)
{
	int	height;

	height = 0;
	while (map->map[height])
		height++;
	return (height);
}

void	draw_circle(t_game *game, t_rect rect, uint32_t c)
{
	int	i;
	int j;

	i = 0;
	while (i < rect.h)
	{
		j = 0;
		while (j < rect.w)
		{
			if ((i - rect.h / 2) * (i - rect.h / 2) + (j - rect.w / 2) * (j - rect.w / 2) <= (rect.w / 2) * (rect.h / 2))
				mlx_pixel_put(game->graphics->init, game->graphics->window, rect.x + j, rect.y + i, color(c));
			j++;
		}
		i++;
	}
}

static void draw_container(t_game *game)
{
	int x;
	int y;
	int width;
	int height;

	width = (get_map_width(game->map) * 10) + 20;
	height = (get_map_height(game->map) * 10) + 30;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_pixel_put(game->graphics->init, game->graphics->window, x + 10, y + 10, color(0x0000007F));
			x++;
		}
		y++;
	}
	mlx_string_put(game->graphics->init, game->graphics->window, 20, 23, color(0xFFFFFFFF), "Debug View");
	(void)game;
}

static void	draw_map_grid(t_game *game)
{
	int x;
	int y;
	int width;
	int height;
	t_rect	rect;

	width = get_map_width(game->map);
	height = get_map_height(game->map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			rect.x = x * 10 + 20;
			rect.y = y * 10 + 30;
			rect.h = 10;
			rect.w = 10;
			if (game->map->map[y] && game->map->map[y][x] == '1')
				draw_rectangle(game->graphics, rect, color(0xFFFFFFFF));
			else if (game->map->map[y] && game->map->map[y][x] == '0')
				draw_rectangle(game->graphics, rect, color(0xFFFFFF55));
			rect.h = 1;
			draw_rectangle(game->graphics, rect, color(0xFFFFFFFF));
			rect.h = 10;
			rect.w = 1;
			draw_rectangle(game->graphics, rect, color(0xFFFFFFFF));
			rect.w = 10;
			x++;
		}
		y++;
	}
	rect.x = 20;
	rect.y = y * 10 + 30;
	rect.w = width * 10;
	rect.h = 1;
	draw_rectangle(game->graphics, rect, color(0xFFFFFFFF));
	rect.x = x * 10 + 20;
	rect.y = 30;
	rect.w = 1;
	rect.h = height * 10 + 1;
	draw_rectangle(game->graphics, rect, color(0xFFFFFFFF));
}

void	debug_view(t_game *game)
{
	t_rect	rect;
	int player_x;
	int	player_y;
	int	sight_angle;
	int	sight_length;
	int	i;
	float	angle_rad;
	int	sight_x;
	int	sight_y;

	draw_container(game);
	draw_map_grid(game);
	player_x = (int)(game->player->pos_x * 10) + 20;
	player_y = (int)(game->player->pos_y * 10) + 30;
	rect.x = player_x - 2;
	rect.y = player_y - 2;
	rect.h = 5;
	rect.w = 5;
	draw_circle(game, rect, 0xFF0000FF);
	sight_angle = -(game->ray->fov / 2);
	while (sight_angle <= game->ray->fov / 2)
	{
		sight_length = 30;
		angle_rad = deg_to_rad(game->player->angle + sight_angle);
		i = 0;
		while (i < sight_length)
		{
			sight_x = player_x + (int)(cos(angle_rad) * i);
			sight_y = player_y + (int)(sin(angle_rad) * i);
			if (sight_x >= 0 && sight_x < get_map_width(game->map) * 10 + 20 &&
				sight_y >= 0 && sight_y < get_map_height(game->map) * 10 + 30)
				mlx_pixel_put(game->graphics->init, game->graphics->window, sight_x, sight_y, color(0xFF00007F));
			i++;
		}
		sight_angle += 1;
	}
}
