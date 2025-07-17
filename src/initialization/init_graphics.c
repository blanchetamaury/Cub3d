/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:24:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:50:39 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = ft_calloc(1, sizeof(t_graphics));
	graphics->frame = 0;
	graphics->init = mlx_init();
	graphics->window = NULL;
	graphics->max_fps = 90;
	return (graphics);
}
