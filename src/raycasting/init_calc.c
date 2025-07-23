/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:43:07 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/23 15:52:56 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	init_angle(t_game *game, int i)
{
	float	rayangle;

	rayangle = (game->player->angle - game->ray->fov / 2) + i
		* game->ray->deltaangle;
	return (rayangle * game->ray->deg_to_rad);
}

void	init_calc(t_game *game, float rad)
{
	game->ray->map_x = (int)game->player->pos_x;
	game->ray->map_y = (int)game->player->pos_y;
	game->ray->cos_x = cos(rad);
	game->ray->sin_y = sin(rad);
	game->ray->ray_x = sqrt(1 + (game->ray->sin_y / game->ray->cos_x)
			* (game->ray->sin_y / game->ray->cos_x));
	game->ray->ray_y = sqrt(1 + (game->ray->cos_x / game->ray->sin_y)
			* (game->ray->cos_x / game->ray->sin_y));
	game->ray->rofract_x = game->player->pos_x - (int)game->player->pos_x;
	game->ray->rofract_y = game->player->pos_y - (int)game->player->pos_y;
}

void	init_dir(t_game *game)
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

float	shade_result(t_game *game, int len)
{
	float	dist;
	float	max_rad;

	game->ray->color_y = (float)len - (HEIGHT_WINDOW - HEIGHT_WINDOW / 3);
	dist = hypotf(game->ray->color_x, game->ray->color_y) / (game->ray->light * 0.125);
	max_rad = hypotf(WIDTH_WINDOW / 2, game->ray->draw_start);
	return (1.0f - (dist / max_rad));
}

void	wall_size_texture(t_game *game, int side, int lineheight)
{
	if (side == 0)
		game->ray->wall_x = game->player->pos_y + game->ray->perpwalldist
			* game->ray->sin_y;
	else
		game->ray->wall_x = game->player->pos_x + game->ray->perpwalldist
			* game->ray->cos_x;
	game->ray->wall_x -= floorf(game->ray->wall_x);
	if (game->ray->door == 1)
	{
		game->ray->tex_x = (int)(game->ray->wall_x * game->texture->door->width);
	}
	else if (game->map->map[game->ray->map_y][game->ray->map_x] == 'Q')
	{
		game->ray->tex_x = (int)(game->ray->wall_x * game->texture->exit->width);
	}
	else
	{
		game->ray->tex_x = (int)(game->ray->wall_x * (float)get_face_width(side,
					game->ray->step_x, game->ray->step_y, game->texture));
	}
	if (((side == 0 && game->ray->cos_x > 0) || (side == 1
			&& game->ray->sin_y < 0)) && game->ray->door == 1)
	{
		game->ray->tex_x = game->texture->door->width - game->ray->tex_x - 1;
	}
	else if ((side == 0 && game->ray->cos_x > 0) || (side == 1
			&& game->ray->sin_y < 0))
		game->ray->tex_x = get_face_width(side, game->ray->step_x,
				game->ray->step_y, game->texture) - game->ray->tex_x - 1;
	if (game->ray->door == 1)
	{
		game->ray->tex_step = 1.0f * game->texture->door->height / lineheight;
	}
	else if (game->map->map[game->ray->map_y][game->ray->map_x] == 'Q')
	{
		game->ray->tex_step = 1.0f * game->texture->exit->height / lineheight;
	}
	else
	{
		game->ray->tex_step = 1.0f * get_face_height(side, game->ray->step_x,
				game->ray->step_y, game->texture) / lineheight;
	}
	game->ray->tex_pos = (game->ray->draw_start - HEIGHT_WINDOW / 2
			+ lineheight / 2) * game->ray->tex_step;
}
