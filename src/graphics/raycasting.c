/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/10 10:30:16 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float	init_angle(t_game *game, int i)
{
	float	deltaAngle;
	float	rayAngle;
	float	deg_to_rad;

	deg_to_rad = 3.14 / 180.0f;
	deltaAngle = FOV / (float)width_window;
	rayAngle = (game->player->angle - FOV / 2) + i * deltaAngle;
	return (rayAngle * deg_to_rad);
}

static void	init_calc(t_game *game, float rad)
{
	game->ray->map_x = (int)game->player->pos_x;
	game->ray->map_y = (int)game->player->pos_y;
	game->ray->cos_x = cos(rad);
	game->ray->sin_y = sin(rad);
	game->ray->ray_x = sqrt(1 + (game->ray->sin_y / game->ray->cos_x) * (game->ray->sin_y / game->ray->cos_x));
	game->ray->ray_y = sqrt(1 + (game->ray->cos_x / game->ray->sin_y) * (game->ray->cos_x / game->ray->sin_y));
	game->ray->rofract_x = game->player->pos_x - (int)game->player->pos_x;
	game->ray->rofract_y = game->player->pos_y - (int)game->player->pos_y;
}

static void	init_dir(t_game *game)
{
	if (game->ray->cos_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->raylength_x = game->ray->rofract_x * game->ray->ray_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->raylength_x = (1 - game->ray->rofract_x) * game->ray->ray_x;
	}
	if (game->ray->sin_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->raylength_y = game->ray->rofract_y * game->ray->ray_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->raylength_y = (1 - game->ray->rofract_y) * game->ray->ray_y;
	}
}

static int	find_wall(t_game *game, int	*alpha)
{
	int	j;
	int side;

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
		*alpha += 20;
		if (*alpha > 255)
			*alpha = 255;
	}
	return (side);
}

int		get_face(int side, int step_x, int step_y)
{
	if (side == 0) // vertical wall
	{
		if (step_x < 0) // west
			return (3);
		else // east
			return (1);
	}
	else
	{
		if (step_y < 0) // north
			return (0);
		else // south
			return (2);
	}
}

int		get_face_height(int side, int step_x, int step_y, t_texture *texture)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0) // north
		return (texture->north->height);
	if (face == 1) // east
		return (texture->east->height);
	if (face == 2) // south
		return (texture->south->height);
	if (face == 3) // west
		return (texture->west->height);
	return (0);
}

int		get_face_width(int side, int step_x, int step_y, t_texture *texture)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0) // north
		return (texture->north->width);
	if (face == 1) // east
		return (texture->east->width);
	if (face == 2) // south
		return (texture->south->width);
	if (face == 3) // west
		return (texture->west->width);
	return (0);
}

void    raycasting(t_game *game)
{
	float	rad;
	float	perpwalldist;
	float	texStep;
	float	texPos;
	float	wallX;
	int		i;
	int		lineheight;
	int		side;
	int		draw_start;
	int		draw_end;
	int		len;
	int		texY;
	int		texX;
	int		alpha;
	float	color_x;
	float	color_y;
	float	dist;
	float	shade;
	float	max_rad;
	float	 color_alpha;
	mlx_color tmp;

	i = 0;
	color_x = 0;
	while (i < width_window)
	{
		alpha = 0;
		rad = init_angle(game, i);
		init_calc(game, rad);
		init_dir(game);
		side = find_wall(game, &alpha);

		if (side == 0)
			perpwalldist = (game->ray->raylength_x - game->ray->ray_x);
		else
			perpwalldist = (game->ray->raylength_y - game->ray->ray_y);
		if (perpwalldist == 0)
			perpwalldist = 1;
		lineheight = (int)(height_window / perpwalldist);
		draw_start = -lineheight / 2 + height_window /2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = lineheight / 2 + height_window /2;
		if (draw_end >= height_window)
			draw_end = height_window - 1;
		len = 0;
		while (len < draw_start) // sky
		{
			color_x = (float)i - width_window / 2;
			color_y = (float)len - height_window / 2;
			dist = hypotf(color_x, color_y);
			max_rad = hypotf(width_window / 2, draw_start);
			shade = 1.0f - (dist / max_rad);
			tmp.r = game->texture->sky->color.r;
			tmp.g = game->texture->sky->color.g;
			tmp.b = game->texture->sky->color.b;
			if (shade < 0)
				tmp.a = 0;
			else
				tmp.a = 255 * (shade / 2);
			mlx_set_image_pixel(game->graphics->init, game->texture->render, i, len, tmp);
			len++;
		}
		len = draw_start;
		if (side == 0)
		    wallX = game->player->pos_y + perpwalldist * game->ray->sin_y;
		else
		    wallX = game->player->pos_x + perpwalldist * game->ray->cos_x;
		wallX -= floorf(wallX);
		texX = (int)(wallX * (float)get_face_width(side, game->ray->step_x, game->ray->step_y, game->texture));
		if ((side == 0 && game->ray->cos_x > 0) || (side == 1 && game->ray->sin_y < 0))
		    texX = get_face_width(side, game->ray->step_x, game->ray->step_y, game->texture) - texX - 1;
		texStep = 1.0f * get_face_height(side, game->ray->step_x, game->ray->step_y, game->texture) / lineheight;
		texPos = (draw_start - height_window / 2 + lineheight / 2) * texStep;
		while (len < draw_end) // wall
		{
			color_x = (float)i - width_window / 2;
			color_y = (float)len - height_window / 2;
			dist = hypotf(color_x, color_y);
			max_rad = hypotf(width_window / 2, draw_start);
			shade = 1.0f - (dist / max_rad);
			texY = (int)texPos & (get_face_height(side, game->ray->step_x, game->ray->step_y, game->texture) - 1);
			texPos += texStep;
			if (side == 0) // vertical wall
			{
				if (game->ray->step_x < 0) // west
					tmp = mlx_get_image_pixel(game->graphics->init, game->texture->west->img, texX, texY);
				else // east
					tmp = mlx_get_image_pixel(game->graphics->init, game->texture->east->img, texX, texY);
				color_alpha = 1.0f - (perpwalldist/ LIGHT);
				if ((255) * (shade / 2) * color_alpha < 0)
					tmp.a = 0;
				else
					tmp.a = (255) * (shade / 2) * color_alpha;
			}
			else
			{
				if (game->ray->step_y < 0) // north
					tmp = mlx_get_image_pixel(game->graphics->init, game->texture->north->img, texX, texY);
				else // south
					tmp = mlx_get_image_pixel(game->graphics->init, game->texture->south->img, texX, texY);
				color_alpha = 1.0f - (perpwalldist/ LIGHT);
				if ((255) * (shade / 2) * color_alpha < 0)
					tmp.a = 0;
				else
					tmp.a = (255) * (shade / 2) * color_alpha;
			}
			mlx_set_image_pixel(game->graphics->init, game->texture->render, i, len, tmp);
			len++;
		}
		int count;

		count = 1;
		while (len < height_window) // ground
		{
			color_x = (float)i - width_window / 2;
			color_y = (float)len - height_window / 2;
			dist = hypotf(color_x, color_y);
			max_rad = hypotf(width_window / 2, draw_end);
			shade = 1.0f - (dist / max_rad);
			tmp.r = game->texture->ground->color.r;
			tmp.g = game->texture->ground->color.g;
			tmp.b = game->texture->ground->color.b;
			if (shade < 0)
				tmp.a = 0;
			else
				tmp.a = 255 * (shade / 2);
			mlx_set_image_pixel(game->graphics->init, game->texture->render, i, len, tmp);
			len++;
			count++; 
		}
		i++;
	}
}
