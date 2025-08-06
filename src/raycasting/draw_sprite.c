/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:21:55 by amblanch          #+#    #+#             */
/*   Updated: 2025/08/06 13:22:23 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	sprite_draw_col(t_game *game, t_image *text, int len, int tex_x)
{
	mlx_color	raw;
	float		shade;
	float		intensity;
	int			k;

	k = game->ray->draw_start;
	while (k < game->ray->draw_end)
	{
		game->ray->color_x = (float)k - WIDTH_WINDOW / 3 - 0;
		shade = shade_result(game->ray, len);
		intensity = (1.0f + game->events->flashlight * 3.0f) * shade
			* (1.0f - (game->ray->transform_y / game->ray->light));
		raw = text[BATTERY].colors[((k - game->ray->draw_start)
				* text[BATTERY].height / game->ray->sprite_height)
			* text[BATTERY].width + tex_x];
		raw = sprite_intensity(raw, intensity);
		if (raw.a)
			mlx_set_image_pixel(game->graphics->init,
				game->img[RENDER], len, k, raw);
		k++;
	}
}

void	sprite_draw_raw(t_game *game, int len, int draw_end_x, float *z_buffer)
{
	t_image	*text;
	int		draw_start_x;
	int		tex_x;

	text = game->text;
	draw_start_x = len;
	while (len < draw_end_x)
	{
		tex_x = (len - draw_start_x) * text[BATTERY].width
			/ game->ray->sprite_width;
		if (game->ray->transform_y <= 0
			|| game->ray->transform_y >= z_buffer[len])
			;
		else
			sprite_draw_col(game, text, len, tex_x);
		len++;
	}
}
