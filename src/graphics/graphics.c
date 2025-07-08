/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/08 15:06:09 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

# define rotSpeed 1

static void	window_info(mlx_window_create_info *info)
{
	ft_bzero(info, sizeof(mlx_window_create_info));
	info->height = height_window;
	info->width = width_window;
	info->title = "test";
	info->is_resizable = 0;
	info->is_fullscreen = 0;
}

static void	key_hook_down(int key, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (key == 41)
		mlx_loop_end(game->graphics->init);
	if (game->key[key] == 0)
	{
		printf("key down = %d\n", key);
		game->key[key] = 1;
	}
}

static void	key_hook_up(int key, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (game->key[key] == 1)
	{
		printf("key up = %d\n", key);
		game->key[key] = 0;
	}
}

static void	draw_rectangle_mlx(t_game *game, int x, int y, int w, int h, mlx_color color)
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
	// Get block at y + 1
	printf("PLAYER X => %f => %d\n", player->pos_x, (int)player->pos_x);
	printf("PLAYER Y => %f => %d\n", player->pos_y, (int)player->pos_y);
	printf("ELEMENT ON TOP => %c\n", map->map[(int)(player->pos_y + 0.5) - 1][(int)player->pos_x]);
	return (map->map[(int)(player->pos_y + 0.9) - 1][(int)player->pos_x] == '1');
}

int checkCollideBottom(t_player *player, t_map *map)
{
	// Get block at y + 1
	printf("PLAYER X => %f => %d\n", player->pos_x, (int)player->pos_x);
	printf("PLAYER Y => %f => %d\n", player->pos_y, (int)player->pos_y);
	printf("ELEMENT ON BOTTOM => %c\n", map->map[(int)(player->pos_y) - 1][(int)player->pos_x]);
	return (map->map[(int)(player->pos_y + 0.1)][(int)player->pos_x] == '1');
}

int checkCollideLeft(t_player *player, t_map *map)
{
	// Get block at y + 1
	printf("PLAYER X => %f => %d\n", player->pos_x, (int)player->pos_x);
	printf("PLAYER Y => %f => %d\n", player->pos_y, (int)player->pos_y);
	printf("ELEMENT ON LEFT => %c\n", map->map[(int)player->pos_y][(int)player->pos_x - 1]);
	return (map->map[(int)(player->pos_y)][(int)(player->pos_x + 0.9) - 1] == '1');
}

int checkCollideRight(t_player *player, t_map *map)
{
	// Get block at y + 1
	printf("PLAYER X => %f => %d\n", player->pos_x, (int)player->pos_x);
	printf("PLAYER Y => %f => %d\n", player->pos_y, (int)player->pos_y);
	printf("ELEMENT ON RIGHT => %c\n", map->map[(int)player->pos_y][(int)player->pos_x - 1]);
	return (map->map[(int)(player->pos_y)][(int)(player->pos_x + 0.1)] == '1');
}

static void	loop(void *param)
{
	t_game		*game;
	mlx_color	bg;
	mlx_color	red;

	game = (t_game *)param;
	bg.rgba = 0x00000000;
	red.rgba = 0xFF0000FF;
	mlx_clear_window(game->graphics->init, game->graphics->window, bg);
	int xt;
	int yt;

	yt = 0;
	while (game->map->map[yt])
	{
		xt = 0;
		//printf("len = %zu | xt = %d\n", ft_strlen(game->map->map[game->player->y]), xt);
		while  (game->map->map[yt][xt])
		{
			if (game->map->map[yt][xt] == '1')
				draw_rectangle(game, xt * 20, yt * 20, 20, 20, 0xAAAAAAFF);
			draw_rectangle(game, xt * 20, yt * 20, 1, 20, 0xFFFFFFFF);
			draw_rectangle(game, xt * 20, yt * 20, 20, 1, 0xFFFFFFFF);
			xt++;
		}
		yt++;
	}
	//printf("x_pos = %f | pos_y = %f | x = %d | y = %d\n", game->player->pos_x, game->player->pos_y, game->player->x, game->player->y);


	float	cos_x;
	float	sin_y;
	float	ray_x;
	float	ray_y;
	float	raylength_x;
	float	raylength_y;
	float	rofract_x;
	float	rofract_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		i;
	mlx_color	vision;

	const float DEG2RAD = 3.14 / 180.0f;
	i = 0;
	while (i < FOV)
	{
		float rad = (game->player->angle + i) * DEG2RAD;
		map_x = (int)game->player->pos_x;
		map_y = (int)game->player->pos_y;
		cos_x = cos(rad);
		sin_y = sin(rad);

		ray_x = sqrt(1 + (sin_y / cos_x) * (sin_y / cos_x));
		ray_y = sqrt(1 + (cos_x / sin_y) * (cos_x / sin_y));
		rofract_x = game->player->pos_x - (int)game->player->pos_x;
		rofract_y = game->player->pos_y - (int)game->player->pos_y;
		if (cos_x < 0)
		{
			step_x = -1;
			raylength_x = rofract_x * ray_x;
		}
		else
		{
			step_x = 1;
			raylength_x = (1 - rofract_x) * ray_x;
		}
		if (sin_y < 0)
		{
			step_y = -1;
			raylength_y = rofract_y * ray_y;
		}
		else
		{
			step_y = 1;
			raylength_y = (1 - rofract_y) * ray_y;
		}
		int hit;
		int j;
		hit = 0;
		j = 0;
		while (hit == 0)
		{
			if (game->map->map[map_y][map_x] == '1')
			{
				hit = 1;
				break ;
			}
			if (255 - j * 20 < 0)
				vision.a = 0;
			else
				vision.a = 255 - j * 20;
			vision.b = 255;
			vision.g = 0;
			vision.r = 0;
			draw_rectangle_mlx(game, (map_x * 20), (map_y* 20), 20, 20, vision);
			if (raylength_x < raylength_y)
			{
				map_x += step_x;
				raylength_x += ray_x;
			}
			else
			{
				map_y += step_y;
				raylength_y += ray_y;
			}
			j++;
		}
		i++;
	}
	if (game->key[26] && !checkCollideTop(game->player, game->map)) // W
		game->player->pos_y -= 0.1;
	else if (game->key[22] && !checkCollideBottom(game->player, game->map)) // S
		game->player->pos_y += 0.1;
	else if (game->key[4] && !checkCollideLeft(game->player, game->map)) // A
		game->player->pos_x -= 0.1;
	else if (game->key[7]&& !checkCollideRight(game->player, game->map)) // D
		game->player->pos_x += 0.1;

	if (game->key[80]) // Arrow	right
		game->player->angle = (game->player->angle + rotSpeed) % 360;
	if (game->key[79]) // Arrow	left
		game->player->angle = (game->player->angle - rotSpeed) % 360;
	draw_rectangle(game, (game->player->pos_x * 20) - 3, (game->player->pos_y * 20) - 3, 6, 6, 0x00FF00FF);
	//mlx_pixel_put_region(game->graphics->init, game->graphics->window, );
}

void	graphic(t_game *game)
{
	mlx_window_create_info info;
	mlx_color color;

	color.a = 0;
	color.b = 100;
	color.g = 20;
	color.r = 20;
	game->map->size = 0;
	game->map->cap = 0;
	ft_stats(game->map->map, &game->map->size, &game->map->cap);
	ft_memset(game->key, 0, 300);
	game->player->x = find_playerx(game->map->map);
	game->player->y = find_playery(game->map->map);
	if (game->map->map[game->player->y][game->player->x] == 'N')
		game->player->angle = 360;
	if (game->map->map[game->player->y][game->player->x] == 'E')
		game->player->angle = 90;
	if (game->map->map[game->player->y][game->player->x] == 'S')
		game->player->angle = 180;
	if (game->map->map[game->player->y][game->player->x] == 'W')
		game->player->angle = 270;
	game->map->map[game->player->y][game->player->x] = '0';
	game->player->pos_y = game->player->y + 0.5;
	game->player->pos_x = game->player->x + 0.5;
	printf("1 x = %d | y = %d\n", game->player->x,  game->player->y);
	window_info(&info);
	game->graphics->init = mlx_init();
	game->graphics->window = mlx_new_window(game->graphics->init, &info);

	mlx_set_fps_goal(game->graphics->init, 60);
	mlx_on_event(game->graphics->init, game->graphics->window, MLX_KEYDOWN, key_hook_down, game);
	mlx_on_event(game->graphics->init, game->graphics->window, MLX_KEYUP, key_hook_up, game);
	mlx_add_loop_hook(game->graphics->init, loop, game);
	mlx_loop(game->graphics->init);

	mlx_destroy_window(game->graphics->init, game->graphics->window);
	mlx_destroy_context(game->graphics->init);
}