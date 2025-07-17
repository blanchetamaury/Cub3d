/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:30 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/17 10:39:08 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rad_floor(t_game *game, float *dir_x, float *dir_y)
{
	float	rad;

	rad = game->player->angle * game->ray->deg_to_rad;
	*dir_x = cosf(rad);
	*dir_y = sinf(rad);
}

static void	init_calc_floor(t_game *game, int i)
{
	static float	dir_x = 0;
	static float	dir_y = 0;
	float			plane_x;
	float			plane_y;
	float			row_d;
	float			tan_half_fov;

	init_rad_floor(game, &dir_x, &dir_y);
	tan_half_fov = tanf((FOV / 2) * (3.14 / 180.0f));
	plane_x = -dir_y * tan_half_fov;
	plane_y = dir_x * tan_half_fov;
	row_d = (0.5 * HEIGHT_WINDOW) / (i - HEIGHT_WINDOW / 2);
	game->ray->floorstep_x = row_d * ((dir_x + plane_x)
			- (dir_x - plane_x)) / WIDTH_WINDOW;
	game->ray->floorstep_y = row_d * ((dir_y + plane_y)
			- (dir_y - plane_y)) / WIDTH_WINDOW;
	game->ray->floor_x = game->player->pos_x + row_d * (dir_x - plane_x);
	game->ray->floor_y = game->player->pos_y + row_d * (dir_y - plane_y);
}

static void	get_pixel_image(t_game *game, t_image *img, int i, int j, int light)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	color_alpha = light / (LIGHT * 46);
	shade = shade_result(game, i % (HEIGHT_WINDOW / 2));
	tmp = img->colors[game->ray->ty * img->width + game->ray->tx];
	if (((tmp.r + tmp.g + tmp.b) / 3) * (shade / (2 + game->events->flashlight * 4)) * color_alpha < 20)
	{
		tmp.r = 0;
		tmp.g = 0;
		tmp.b = 0;
	}
	else
	{
		tmp.r = tmp.r * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
		tmp.g = tmp.g * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
		tmp.b = tmp.b * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
	}
	mlx_set_image_pixel(game->graphics->init, game->texture->render, j, i, tmp);
}

static void	calc_tx_and_ty(t_game *game, t_image *img)
{
	game->ray->tx = (int)(img->width * (game->ray->floor_x
				- (int)game->ray->floor_x)) & (img->width - 1);
	game->ray->ty = (int)(img->height * (game->ray->floor_y
				- (int)game->ray->floor_y)) & (img->height - 1);
}

void	raycasting_floor(t_game *game)
{
	int	i;
	int	j;
	int count;
	mlx_color	color[WIDTH_WINDOW * 1];

	i = 0;
	j = 0;
	while (i < HEIGHT_WINDOW)
	{
		init_calc_floor(game, i);
		j = 0;
		while (j < WIDTH_WINDOW)
		{
			game->ray->color_x = (float)j - WIDTH_WINDOW / 3 - 60;
			calc_tx_and_ty(game, game->texture->sky);
			get_pixel_image(game, game->texture->ground, i, j, i);
			calc_tx_and_ty(game, game->texture->ground);
			get_pixel_image(game, game->texture->sky,
				HEIGHT_WINDOW - i - 1, j, HEIGHT_WINDOW - (HEIGHT_WINDOW - i - 1));
			game->ray->floor_x += game->ray->floorstep_x;
			game->ray->floor_y += game->ray->floorstep_y;
			j++;
		}
		count = 0;
		mlx_get_image_region(game->graphics->init, game->texture->render, 0, i, WIDTH_WINDOW, 1, color);
		while (count < 3)
		{
			mlx_set_image_region(game->graphics->init, game->texture->render, 0, i + count, WIDTH_WINDOW, 1, color);
			count++;
		}
		count = 0;
		mlx_get_image_region(game->graphics->init, game->texture->render, 0, HEIGHT_WINDOW - i - 1, WIDTH_WINDOW, 1, color);
		while (count < 3)
		{
			mlx_set_image_region(game->graphics->init, game->texture->render, 0, (HEIGHT_WINDOW - i - 1) - count, WIDTH_WINDOW, 1, color);
			count++;
		}
		i += count;
	}
}
