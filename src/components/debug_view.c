/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:37:31 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/17 09:03:59 by rgodet           ###   ########.fr       */
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

static void	draw_circle(t_game *game, int x, int y, int w, int h, uint32_t c)
{
	int	i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if ((i - h / 2) * (i - h / 2) + (j - w / 2) * (j - w / 2) <= (w / 2) * (h / 2))
				mlx_pixel_put(game->graphics->init, game->graphics->window, x + j, y + i, color(c));
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

	width = get_map_width(game->map);
	height = get_map_height(game->map);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (game->map->map[y] && game->map->map[y][x] == '1')
				draw_rectangle(game->graphics, x * 10 + 20, y * 10 + 30, 10, 10, color(0xFFFFFFFF));
			else if (game->map->map[y] && game->map->map[y][x] == '0')
				draw_rectangle(game->graphics, x * 10 + 20, y * 10 + 30, 10, 10, color(0xFFFFFF55));
			draw_rectangle(game->graphics, x * 10 + 20, y * 10 + 30, 10, 1, color(0xFFFFFFFF));
			draw_rectangle(game->graphics, x * 10 + 20, y * 10 + 30, 1, 10, color(0xFFFFFFFF));
			x++;
		}
		y++;
	}
	draw_rectangle(game->graphics, 20, y * 10 + 30, width * 10, 1, color(0xFFFFFFFF));
	draw_rectangle(game->graphics, x * 10 + 20, 30, 1, height * 10 + 1, color(0xFFFFFFFF));
}

void	debug_view(t_game *game)
{
	draw_container(game);
	draw_map_grid(game);
	int player_x = (int)(game->player->pos_x * 10) + 20;
	int player_y = (int)(game->player->pos_y * 10) + 30;
	draw_circle(game, player_x - 2, player_y - 2, 5, 5, 0xFF0000FF);

	// Draw line of sight

	int sight_angle = -(game->ray->fov/2);
	while (sight_angle <= game->ray->fov/2)
	{
		int			sight_length = 30;
		float		angle_rad = deg_to_rad(game->player->angle + sight_angle);

		int i = 0;
		while (i < sight_length)
		{
			int sight_x = player_x + (int)(cos(angle_rad) * i);
			int sight_y = player_y + (int)(sin(angle_rad) * i);

			if (sight_x >= 0 && sight_x < get_map_width(game->map) * 10 + 20 &&
				sight_y >= 0 && sight_y < get_map_height(game->map) * 10 + 30)
				mlx_pixel_put(game->graphics->init, game->graphics->window, sight_x, sight_y, color(0xFF00007F));

			i++;
		}
		sight_angle += 1; // Increment angle for next line of sight
	}


}

/*
int xt = 0;
int yt = 0;
mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->map->img, 0, 0);
while (game->map->map[yt])
{
xt = 0;
while  (game->map->map[yt][xt])
{
if (game->map->map[yt][xt] == ' ')
{
xt++;
continue;
}
if (game->map->map[yt][xt] == '1')
draw_rectangle(game, xt * 20, yt * 20, 20, 20, 0xAAAAAAFF);
draw_rectangle(game, xt * 20, yt * 20, 1, 20, 0xFFFFFFFF);
draw_rectangle(game, xt * 20, yt * 20, 20, 1, 0xFFFFFFFF);
xt++;
}
yt++;
}
draw_rectangle(game, (game->player->pos_x * 20) - 3, (game->player->pos_y * 20) - 3, 6, 6, 0x00FF00FF);
*/