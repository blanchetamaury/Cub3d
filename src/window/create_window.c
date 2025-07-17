/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:18:50 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/17 10:45:31 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_window(t_graphics *graphics)
{
	mlx_window_create_info	*info;

	info = init_window_info();
	graphics->window = mlx_new_window(graphics->init, info);
	mlx_set_fps_goal(graphics->init, graphics->max_fps);
	//mlx_key_hook(game->graphics->window, key_hook_down, game);
	//mlx_key_release_hook(game->graphics->window, key_hook_up, game);
}