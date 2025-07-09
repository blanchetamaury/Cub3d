/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:02:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 11:23:42 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	subscribe_events(t_graphics *graphics, t_events *events)
{
	subscribe_keydown(graphics, events);
	subscribe_keyup(graphics, events);
	subscribe_window(graphics, events);
}