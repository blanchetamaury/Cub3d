/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:21:55 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 10:28:39 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_window_create_info	*init_window_info(void)
{
	mlx_window_create_info	*info;

	info = ft_calloc(1, sizeof(mlx_window_create_info));
	info->height = height_window;
	info->width = width_window;
	info->title = "cub3d";
#ifdef BONUS
	info->title = "cub3d - Bonus";
#endif
	return (info);
}