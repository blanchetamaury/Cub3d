/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/10 16:56:46 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sky(t_game *game, int i)
{
	mlx_color	tmp;
	float		shade;
	int			len;

	len = 0;
	while (len < game->ray->draw_start)
	{
		shade = shade_result(game, len);
		tmp.r = 0;//game->texture->sky->color.r;
		tmp.g = 0;//game->texture->sky->color.g;
		tmp.b = 0;//game->texture->sky->color.b;
		if (shade < 0)
			tmp.a = 0;
		else
			tmp.a = 255 * (shade / (2 + (game->events->flashlight * 4)));
		mlx_set_image_pixel(game->graphics->init,
			game->texture->render, i, len, tmp);
		len++;
	}
}

void	draw_wall(t_game *game, int len, int side, int i)
{
	float		shade;
	float		color_alpha;
	mlx_color	tmp;

	while (len < game->ray->draw_end)
	{
		shade = shade_result(game, len);
		game->ray->texY = (int)game->ray->texPos & (get_face_height(side, game->ray->step_x, game->ray->step_y, game->texture) - 1);
		game->ray->texPos += game->ray->texStep;
		if (side == 0)
		{
			if (game->ray->step_x < 0)
				tmp = mlx_get_image_pixel(game->graphics->init, game->texture->west->img, game->ray->texX, game->ray->texY);
			else
				tmp = mlx_get_image_pixel(game->graphics->init, game->texture->east->img, game->ray->texX, game->ray->texY);
			color_alpha = 1.0f - (game->ray->perpwalldist/ LIGHT);
			if ((255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha < 20)
				tmp.a = 20;
			else
				tmp.a = (255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha;
		}
		else
		{
			if (game->ray->step_y < 0)
				tmp = mlx_get_image_pixel(game->graphics->init, game->texture->north->img, game->ray->texX, game->ray->texY);
			else
				tmp = mlx_get_image_pixel(game->graphics->init, game->texture->south->img, game->ray->texX, game->ray->texY);
			color_alpha = 1.0f - (game->ray->perpwalldist/ LIGHT);
			if ((255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha < 20)
				tmp.a = 20;
			else
				tmp.a = (255) * (shade / (2 + (game->events->flashlight * 4))) * color_alpha;
		}
		mlx_set_image_pixel(game->graphics->init, game->texture->render, i, len, tmp);
		len++;
	}
}

void	draw_ground(t_game *game, int len, int i)
{
	float		shade;
	mlx_color 	tmp;

	while (len < height_window)
	{
		shade = shade_result(game, len);
		tmp.r = 0;//game->texture->ground->color.r;
		tmp.g = 0;//game->texture->ground->color.g;
		tmp.b = 0;//game->texture->ground->color.b;
		if (shade < 0)
			tmp.a = 0;
		else
			tmp.a = 255 * (shade / (2 + (game->events->flashlight * 4)));
		mlx_set_image_pixel(game->graphics->init, game->texture->render, i, len, tmp);
		len++;
	}
}
