/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:30 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/26 14:00:36 by amaury           ###   ########.fr       */
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
	float			dir_x;
	float			dir_y;
	float			row_d;
	float			tan_half_fov;

	dir_x = 0;
	dir_y = 0;
	init_rad_floor(game, &dir_x, &dir_y);
	tan_half_fov = tanf((game->ray->fov / 2) * (3.14 / 180.0f));
	row_d = (0.5 * HEIGHT_WINDOW) / (i - HEIGHT_WINDOW / 2);
	game->ray->floorstep_x = row_d * ((dir_x + (-dir_y * tan_half_fov))
			- (dir_x - (-dir_y * tan_half_fov))) / WIDTH_WINDOW;
	game->ray->floorstep_y = row_d * ((dir_y + (dir_x * tan_half_fov))
			- (dir_y - (dir_x * tan_half_fov))) / WIDTH_WINDOW;
	game->ray->floor_x = game->player->pos_x + row_d
		* (dir_x - (-dir_y * tan_half_fov));
	game->ray->floor_y = game->player->pos_y + row_d
		* (dir_y - (dir_x * tan_half_fov));
}

static void	get_pixel_image(t_game *game, t_image *img, int j)
{
	mlx_color	tmp;
	float		shade;

	shade = shade_result(game->ray, game->ray->i
			% (HEIGHT_WINDOW / 2) / game->ray->light) / 4;
	tmp = img->colors[game->ray->ty * img->width + game->ray->tx];
	if (is_bonus())
		tmp = texture_shader(tmp, (shade * game->ray->light)
				/ (2 + game->events->flashlight * 4));
	mlx_set_image_pixel(game->graphics->init, game->img[RENDER],
		j, game->ray->i, tmp);
}

static void	calc_tx_and_ty(t_game *game, t_image *img)
{
	game->ray->tx = (int)(img->width * (game->ray->floor_x
				- (int)game->ray->floor_x)) & (img->width - 1);
	game->ray->ty = (int)(img->height * (game->ray->floor_y
				- (int)game->ray->floor_y)) & (img->height - 1);
}

static int	raycasting_floor_print(t_game *game, int i)
{
	static mlx_color	color_sky[WIDTH_WINDOW * 1];
	static mlx_color	color_ground[WIDTH_WINDOW * 1];
	int					count;

	count = 0;
	mlx_get_image_region(game->graphics->init, game->img[RENDER],
		0, i, WIDTH_WINDOW, 1, color_sky);
	mlx_get_image_region(game->graphics->init, game->img[RENDER],
		0, HEIGHT_WINDOW - i - 1, WIDTH_WINDOW, 1, color_ground);
	while (count < 3)
	{
		mlx_set_image_region(game->graphics->init, game->img[RENDER],
			0, i + count, WIDTH_WINDOW, 1, color_sky);
		mlx_set_image_region(game->graphics->init, game->img[RENDER],
			0, (HEIGHT_WINDOW - i - 1) - count++,
			WIDTH_WINDOW, 1, color_ground);
	}
	return (count);
}

void	raycasting_floor(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < HEIGHT_WINDOW)
	{
		init_calc_floor(game, i);
		j = 0;
		game->ray->draw_start = i;
		while (j < WIDTH_WINDOW)
		{
			game->ray->color_x = (float)j - WIDTH_WINDOW / 3 - 60;
			calc_tx_and_ty(game, &game->text[SKY]);
			game->ray->i = i;
			get_pixel_image(game, &game->text[GROUND], j);
			calc_tx_and_ty(game, &game->text[GROUND]);
			game->ray->i = HEIGHT_WINDOW - i - 1;
			get_pixel_image(game, &game->text[SKY], j);
			game->ray->floor_x += game->ray->floorstep_x;
			game->ray->floor_y += game->ray->floorstep_y;
			j++;
		}
		i += raycasting_floor_print(game, i);
	}
}
