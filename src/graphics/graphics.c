/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 15:16:55 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	graphic(t_game *game)
{
	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_loop(game->graphics->init);

	mlx_destroy_image(game->graphics->init, game->map->img);
	mlx_destroy_window(game->graphics->init, game->graphics->window);
	mlx_destroy_context(game->graphics->init);
}