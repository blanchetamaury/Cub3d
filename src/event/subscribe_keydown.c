/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_keydown.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:04:46 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 11:43:13 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		on_keydown(int key, void *param)
{
	t_events	*events;

	events = param;
	if (key == 26)
		events->move_forward = 1;
	else if (key == 22)
		events->move_backward = 1;
	else if (key == 4)
		events->move_left = 1;
	else if (key == 7)
		events->move_right = 1;
	else if (key == 79)
		events->rotate_left = 1;
	else if (key == 80)
		events->rotate_right = 1;
	else if (key == 41)
		events->exit = 1;
	else if (key == 60)
		events->debug_enabled = !events->debug_enabled;
}

void	subscribe_keydown(t_graphics *graphics, t_events *events)
{
	mlx_on_event(graphics->init, graphics->window, MLX_KEYDOWN, on_keydown, events);
}