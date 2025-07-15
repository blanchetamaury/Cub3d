/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:30 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/15 10:46:27 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_graphics *graphics, int x, int y, int w, int h,
	mlx_color c)
{
	mlx_color	region[w * h];
	int			i;

	i = 0;
	while (i < w * h)
	{
		region[i] = c;
		i++;
	}
	mlx_pixel_put_region(graphics->init, graphics->window, x, y, w, h, region);
}