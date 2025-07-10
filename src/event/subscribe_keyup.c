/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_keyup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:07:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 10:38:08 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		on_keyup(int key, void *param)
{
	t_events	*events;

	events = param;
	if (key == 26)
		events->move_forward = 0;
	else if (key == 22)
		events->move_backward = 0;
	else if (key == 4)
		events->move_left = 0;
	else if (key == 7)
		events->move_right = 0;
	else if (key == 79)
		events->rotate_left = 0;
	else if (key == 80)
		events->rotate_right = 0;
}

void	subscribe_keyup(t_graphics *graphics, t_events *events)
{
	mlx_on_event(graphics->init, graphics->window, MLX_KEYUP, on_keyup, events);
}