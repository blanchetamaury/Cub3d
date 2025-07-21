/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:18:50 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/18 14:28:29 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_window(t_graphics *graphics)
{
	graphics->info = init_window_info();
	graphics->window = mlx_new_window(graphics->init, graphics->info);
	mlx_set_fps_goal(graphics->init, graphics->max_fps);
}
