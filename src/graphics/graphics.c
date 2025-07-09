/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 11:44:46 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

# define rotSpeed 3

void	draw_rectangle_mlx(t_game *game, int x, int y, int w, int h, mlx_color color)
{
	int	i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			mlx_pixel_put(game->graphics->init, game->graphics->window, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_rectangle(t_game *game, int x, int y, int w, int h, uint32_t color)
{
	int	i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			mlx_pixel_put(game->graphics->init, game->graphics->window, x + j, y + i, (mlx_color){ .rgba = color });
			j++;
		}
		i++;
	}
}

int checkCollideTop(t_player *player, t_map *map)
{
	return (map->map[(int)(player->pos_y + 0.9) - 1][(int)player->pos_x] == '1');
}

int checkCollideBottom(t_player *player, t_map *map)
{
	return (map->map[(int)(player->pos_y + 0.1)][(int)player->pos_x] == '1');
}

int checkCollideLeft(t_player *player, t_map *map)
{
	return (map->map[(int)(player->pos_y)][(int)(player->pos_x + 0.9) - 1] == '1');
}

int checkCollideRight(t_player *player, t_map *map)
{
	return (map->map[(int)(player->pos_y)][(int)(player->pos_x + 0.1)] == '1');
}

static void	loop(void *param)
{
	t_game		*game;
	mlx_color	bg;

	game = (t_game *)param;
	bg.rgba = 0x000000FF;
	mlx_clear_window(game->graphics->init, game->graphics->window, bg);
	//printf("x_pos = %f | pos_y = %f | x = %d | y = %d\n", game->player->pos_x, game->player->pos_y, game->player->x, game->player->y);


	raycasting(game);

	int xt;
	int yt;
	
	if (game->events->move_forward && !checkCollideTop(game->player, game->map)) // W
		game->player->pos_y -= 0.1f;
	if (game->events->move_backward && !checkCollideBottom(game->player, game->map)) // S
		game->player->pos_y += 0.1f;
	if (game->events->move_left && !checkCollideLeft(game->player, game->map)) // A
		game->player->pos_x -= 0.1f;
	if (game->events->move_right && !checkCollideRight(game->player, game->map)) // D
		game->player->pos_x += 0.1f;
	if (game->events->exit) // Escape
		mlx_loop_end(game->graphics->init);

	/*if (game->key[80]) // Arrow	right
		game->player->angle = (game->player->angle + rotSpeed) % 360;
	if (game->key[79]) // Arrow	left
		game->player->angle = (game->player->angle - rotSpeed) % 360;*/
	draw_rectangle(game, (game->player->pos_x * 20) - 3, (game->player->pos_y * 20) - 3, 6, 6, 0x00FF00FF);

	yt = 0;
	mlx_put_image_to_window(game->graphics->init, game->graphics->window, game->map->img, 0, 0);
	while (game->map->map[yt])
	{
		xt = 0;
		//printf("len = %zu | xt = %d\n", ft_strlen(game->map->map[game->player->y]), xt);
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

	int mouse_x = width_window/2;
	int mouse_y = 0;
	mlx_mouse_get_pos(game->graphics->init, &mouse_x, &mouse_y);

	printf("Angle => %f\n", (mouse_x / (float)width_window) * 360.0f );
	if ((mouse_x / (float)width_window) * 360.0f == 0 && game->graphics->frame % 3 == 0)
		mlx_mouse_move(game->graphics->init, game->graphics->window, width_window - 2, height_window/2);
	else if ((mouse_x / (float)width_window) * 360.0f > 359.0f && game->graphics->frame % 3 == 0)
		mlx_mouse_move(game->graphics->init, game->graphics->window, 2, height_window/2);
	game->player->angle = (mouse_x / (float)width_window) * 360.0f;

	//mlx_pixel_put_region(game->graphics->init, game->graphics->window, );
	game->graphics->frame++;
}

void	graphic(t_game *game)
{
	ft_stats(game->map->map, &game->map->size, &game->map->cap);


	printf("1 x = %d | y = %d\n", game->player->x,  game->player->y);
	game->map->img = mlx_new_image(game->graphics->init, width_window, height_window);

	mlx_add_loop_hook(game->graphics->init, loop, game);
	mlx_loop(game->graphics->init);

	mlx_destroy_image(game->graphics->init, game->map->img);
	mlx_destroy_window(game->graphics->init, game->graphics->window);
	mlx_destroy_context(game->graphics->init);
}