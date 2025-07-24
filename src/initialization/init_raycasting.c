/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:33:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/24 12:16:49 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_raycasting	*init_raycasting(void)
{
	t_raycasting	*ray;

	ray = NULL;
	ray = ft_calloc(1, sizeof(t_raycasting));
	ray->fov = 70;
	ray->light = LIGHT_OFF;
	return (ray);
}
