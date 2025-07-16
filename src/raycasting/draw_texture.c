/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 11:10:00 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_wall_face_north_and_south(t_game *game, int i, int len)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	shade = shade_result(game, len);
	if (game->ray->step_y < 0)
		tmp = game->texture->north->colors[game->ray->tex_y
			* game->texture->north->width + game->ray->tex_x];
	else
		tmp = game->texture->south->colors[game->ray->tex_y
			* game->texture->south->width + game->ray->tex_x];
	color_alpha = 1.0f - (game->ray->perpwalldist / LIGHT);
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
	mlx_set_image_pixel(game->graphics->init, game->texture->render,
		i, len, tmp);
}

static void	draw_wall_face_west_and_east(t_game *game, int i, int len)
{
	mlx_color	tmp;
	float		shade;
	float		color_alpha;

	shade = shade_result(game, len);
	if (game->ray->step_x < 0)
		tmp = game->texture->west->colors[game->ray->tex_y
				* game->texture->west->width + game->ray->tex_x];
	else
		tmp = game->texture->east->colors[game->ray->tex_y
				* game->texture->east->width + game->ray->tex_x];
	color_alpha = 1.0f - (game->ray->perpwalldist / LIGHT);
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
	mlx_set_image_pixel(game->graphics->init, game->texture->render,
		i, len, tmp);
}

void	draw_wall(t_game *game, int len, int side, int i)
{
	while (len < game->ray->draw_end)
	{
		game->ray->tex_y = (int)game->ray->tex_pos & (get_face_height(side,
					game->ray->step_x, game->ray->step_y, game->texture) - 1);
		game->ray->tex_pos += game->ray->tex_step;
		if (side == 0)
			draw_wall_face_west_and_east(game, i, len);
		else
			draw_wall_face_north_and_south(game, i, len);
		len++;
	}
}
