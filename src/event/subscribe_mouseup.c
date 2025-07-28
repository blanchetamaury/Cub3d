/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_mouseup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:07:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/28 09:35:59 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	next_element(t_game *game, int *x, int *y)
{
	float	ray_x;
	float	ray_y;
	int		dist;

	ray_x = game->player->pos_x;
	ray_y = game->player->pos_y;
	dist = 0;
	while (game->map->map[(int)ray_y][(int)ray_x] == '0'
		|| game->map->map[(int)ray_y][(int)ray_x] == 'B')
	{
		ray_x += cos(deg_to_rad(game->player->angle));
		ray_y += sin(deg_to_rad(game->player->angle));
		dist++;
	}
	*x = (int)ray_x;
	*y = (int)ray_y;
	if (dist > 2 || dist == 0)
	{
		*x = 0;
		*y = 0;
	}
}

static void	on_game_click(t_game *game)
{
	int	x;
	int	y;

	next_element(game, &x, &y);
	if (game->map->map[y][x] == 'P')
	{
		game->ray->frame = 0;
		game->map->map[y][x] = 'M';
	}
	else if (game->map->map[y][x] == 'O')
	{
		game->ray->frame = 0;
		game->map->map[y][x] = 'C';
	}
	else if (game->map->map[y][x] == 'Q')
		change_view(game, 4);
}

static void	on_menu_click(t_game *game)
{
	if (game->graphics->selection == 1)
	{
		change_view(game, 1);
		game->player->angle = game->player->base_angle;
	}
	else if (game->graphics->selection == 3)
	{
		change_view(game, 3);
		game->player->inventory_page = 3;
	}
	else if (game->graphics->selection == 4)
		mlx_loop_end(game->graphics->init);
}

static void	on_mouseup(int key, void *param)
{
	t_game	*game;

	game = param;
	if (game->graphics->view == 0)
		on_menu_click(game);
	else if (game->graphics->view == 1)
		on_game_click(game);
	else if (game->graphics->view == 4 || game->graphics->view == 5)
	{
		if (game->graphics->selection == 1 || game->graphics->selection == 2)
		{
			reset_game(game);
			change_view(game, game->graphics->selection == 1);
		}
		else if (game->graphics->selection == 3)
			mlx_loop_end(game->graphics->init);
	}
	(void) key;
}

void	subscribe_mouseup(t_graphics *graphics, t_game *game)
{
	mlx_on_event(graphics->init, graphics->window, MLX_MOUSEUP,
		on_mouseup, game);
}
