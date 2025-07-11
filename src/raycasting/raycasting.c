/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/11 10:56:15 by amblanch         ###   ########.fr       */
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

void	raycasting_floor(t_game *game)
{
	int i;
	int	j;
	int	p;
	int	tx;
	int	ty;
	float	posz;
	float	row_d;
	float	raydirx0;
	float	raydiry0;
	float	raydirx1;
	float	raydiry1;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	floorstep_x;
	float	floorstep_y;
	float	floor_x;
	float	floor_y;
	float	rad;
	float	shade;
	float	color_alpha;
	mlx_color	tmp;

	i = 0;
	j = 0;
	while (i < height_window)
	{
		rad = game->player->angle * (3.14/180.0f);
		dir_x = cosf(rad);
		dir_y = sinf(rad);
		plane_x = -dir_y * tanf((FOV/2) *(3.14/180.0f));
		plane_y = dir_x * tanf((FOV/2) *(3.14/180.0f));
		raydirx0 = dir_x - plane_x;
		raydiry0 = dir_y - plane_y;
		raydirx1 = dir_x + plane_x;
		raydiry1 = dir_y + plane_y;
		p = i - height_window / 2;
		posz = 0.5 * height_window;
		row_d = posz / p;
		floorstep_x = row_d * (raydirx1 - raydirx0) / width_window;
		floorstep_y = row_d * (raydiry1 - raydiry0) / width_window;
		floor_x = game->player->pos_x + row_d * raydirx0;
		floor_y = game->player->pos_y + row_d * raydiry0;
		
		j = 0;
		while (j < width_window)
		{
			game->ray->color_x = (float)i - width_window / 3 - 60;
			shade = shade_result(game, i);
			color_alpha = 1.0f - ((floor_x) / LIGHT);
			tx = (int)(game->texture->sky->width * (floor_x - (int)floor_x)) & (game->texture->sky->width - 1);
			ty = (int)(game->texture->sky->height * (floor_y - (int)floor_y)) & (game->texture->sky->height - 1);
			tmp = mlx_get_image_pixel(game->graphics->init, game->texture->ground->img, tx, ty);
			if ((255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha < 20)
				tmp.a = 20;
			else
				tmp.a = (255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha;
			mlx_set_image_pixel(game->graphics->init, game->texture->render, j, i, tmp);
			tx = (int)(game->texture->ground->width * (floor_x - (int)floor_x)) & (game->texture->ground->width - 1);
			ty = (int)(game->texture->ground->height * (floor_y - (int)floor_y)) & (game->texture->ground->height - 1);
			tmp = mlx_get_image_pixel(game->graphics->init, game->texture->sky->img, tx, ty);
			if ((255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha < 20)
				tmp.a = 20;
			else
				tmp.a = (255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha;
			mlx_set_image_pixel(game->graphics->init, game->texture->render, j, height_window - i - 1, tmp);
			floor_x += floorstep_x;
			floor_y += floorstep_y;
			j++;
		}
		i++;
	}
}

void	raycasting(t_game *game)
{
	int		i;
	int		side;
	int		lineheight;

	i = 0;
	raycasting_floor(game);
	while (i < width_window)
	{
		
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game);
		lineheight = draw_size_wall(game, side);
		game->ray->color_x = (float)i - width_window / 3 - 60;
		//draw_sky(game, i);
		wall_size_texture(game, side, lineheight);
		draw_wall(game, game->ray->draw_start, side, i);
		//draw_ground(game, game->ray->draw_end, i);
		i++;
	}
}
