/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:23:33 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 15:42:19 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_color	color(uint32_t color)
{
	mlx_color	c;

	c.rgba = color;
	return (c);
}

void	set_region_opacity(mlx_color *color, int size, uint8_t opacity)
{
	int			i;

	i = 0;
	while (i < size)
	{
		color[i].a *= opacity / 255.0f;
		i++;
	}
}
