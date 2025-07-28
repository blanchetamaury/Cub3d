/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:37:23 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/28 10:41:06 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_color	sprite_intensity(mlx_color raw, float intensity)
{
	if (raw.r * intensity < 20)
		raw.r = 0;
	if (raw.g * intensity < 20)
		raw.g = 0;
	if (raw.b * intensity < 20)
		raw.b = 0;
	if (raw.r * intensity > 230)
		raw.r = 230 * (230 / raw.r);
	if (raw.g * intensity > 230)
		raw.g = 230 * (230 / raw.g);
	if (raw.b * intensity > 230)
		raw.b = 230 * (230 / raw.b);
	if (raw.r * intensity <= 230 && raw.r * intensity >= 20)
		raw.r = raw.r * intensity;
	if (raw.g * intensity <= 230 && raw.g * intensity >= 20)
		raw.g = raw.g * intensity;
	if (raw.b * intensity <= 230 && raw.b * intensity >= 20)
		raw.b = raw.b * intensity;
	return (raw);
}

float	shade_result(t_raycasting *ray, int len)
{
	float	dist;
	float	max_rad;
	float	result;

	ray->color_y = (float)len - (HEIGHT_WINDOW - HEIGHT_WINDOW / 3);
	dist = hypotf(ray->color_x, ray->color_y) / (ray->light * 0.125);
	max_rad = hypotf(WIDTH_WINDOW / 2, ray->draw_start);
	result = 1.0f - (dist / max_rad);
	if (result < 0)
		result = 0;
	if (result > 1)
		result = 1.0;
	return (result);
}

mlx_color	texture_shader(mlx_color tmp, float shade)
{
	if ((int)tmp.r * shade <= 20)
		tmp.r = 0;
	else if ((int)tmp.r * shade > 230)
		tmp.r = 230;
	else
		tmp.r = (int)tmp.r * shade;
	if ((int)tmp.g * shade <= 20)
		tmp.g = 0;
	else if ((int)tmp.g * shade > 230)
		tmp.g = 230;
	else
		tmp.g = (int)tmp.g * shade;
	if ((int)tmp.b * shade <= 20)
		tmp.b = 0;
	else if ((int)tmp.b * shade >= 230)
		tmp.b = 230;
	else
		tmp.b = (int)tmp.b * shade;
	return (tmp);
}
