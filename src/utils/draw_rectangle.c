/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:45:30 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 08:45:07 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_graphics *graphics, t_rect rect, mlx_color c)
{
	mlx_color	region[rect.w * rect.h];
	int			i;

	i = 0;
	while (i < rect.w * rect.h)
	{
		region[i] = c;
		i++;
	}
	mlx_pixel_put_region(graphics->init, graphics->window, rect.x, rect.y, rect.w, rect.h, region);
}