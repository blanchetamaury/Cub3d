/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:14:31 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 11:16:18 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		on_window_event(int event, void *param)
{
	t_graphics	*graphics;

	graphics = param;
	if (event == 0)
		mlx_loop_end(graphics->init);
}

void	subscribe_window(t_graphics *graphics, t_events *events)
{
	(void) events;
	mlx_on_event(graphics->init, graphics->window, MLX_WINDOW_EVENT, on_window_event, graphics);
}