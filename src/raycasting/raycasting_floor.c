/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:30 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 10:08:44 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rad_floor(t_game *game, float *dir_x, float *dir_y)
{
	float	rad;

	rad = game->player->angle * (3.14 / 180.0f);
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

	init_rad_floor(game, &dir_x, &dir_y);
	plane_x = -dir_y * tanf((FOV / 2) *(3.14 / 180.0f));
	plane_y = dir_x * tanf((FOV / 2) *(3.14 / 180.0f));
	row_d = (0.5 * HEIGHT_WINDOW) / (i - HEIGHT_WINDOW / 2);
	game->ray->floorstep_x = row_d * ((dir_x + plane_x)
			- (dir_x - plane_x)) / WIDTH_WINDOW;
	game->ray->floorstep_y = row_d * ((dir_y + plane_y)
			- (dir_y - plane_y)) / WIDTH_WINDOW;
	game->ray->floor_x = game->player->pos_x + row_d * (dir_x - plane_x);
	game->ray->floor_y = game->player->pos_y + row_d * (dir_y - plane_y);
}

static void	get_pixel_image(t_game *game, mlx_image img, int i, int j)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	color_alpha = 1.0f - ((HEIGHT_WINDOW % (HEIGHT_WINDOW / 2))
			/ (LIGHT * 1000));
	shade = shade_result(game, i % (HEIGHT_WINDOW / 2));
	tmp = mlx_get_image_pixel(game->graphics->init, img,
			game->ray->tx, game->ray->ty);
	if (255 * (shade / (2 + game->events->flashlight * 4)) * color_alpha < 20)
		tmp.a = 20;
	else
		tmp.a = (255) * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
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
			get_pixel_image(game, game->texture->ground->img, i, j);
			calc_tx_and_ty(game, game->texture->ground);
			get_pixel_image(game, game->texture->sky->img,
				HEIGHT_WINDOW - i - 1, j);
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
