/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:38:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 10:10:51 by amblanch         ###   ########.fr       */
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
		tmp = mlx_get_image_pixel(game->graphics->init,
				game->texture->north->img, game->ray->tex_x, game->ray->tex_y);
	else
		tmp = mlx_get_image_pixel(game->graphics->init,
				game->texture->south->img, game->ray->tex_x, game->ray->tex_y);
	color_alpha = 1.0f - (game->ray->perpwalldist / LIGHT);
	if (255 * (shade / (2 + game->events->flashlight * 4)) * color_alpha < 20)
		tmp.a = 20;
	else
		tmp.a = 255 * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
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
		tmp = mlx_get_image_pixel(game->graphics->init,
				game->texture->west->img, game->ray->tex_x, game->ray->tex_y);
	else
		tmp = mlx_get_image_pixel(game->graphics->init,
				game->texture->east->img, game->ray->tex_x, game->ray->tex_y);
	color_alpha = 1.0f - (game->ray->perpwalldist / LIGHT);
	if (255 * (shade / (2 + game->events->flashlight * 4)) * color_alpha < 20)
		tmp.a = 20;
	else
		tmp.a = 255 * (shade / (2 + game->events->flashlight * 4))
			* color_alpha;
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
