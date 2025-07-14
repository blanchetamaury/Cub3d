/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:00:18 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:50:33 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_events	*init_events(void)
{
	t_events	*events;

	events = ft_calloc(1, sizeof(t_events));
	events->move_forward = 0;
	events->move_backward = 0;
	events->move_left = 0;
	events->move_right = 0;
	return (events);
}
