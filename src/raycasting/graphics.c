/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/16 10:42:40 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	graphic(t_game *game)
{
	game->ray->deltaangle = FOV / (float)WIDTH_WINDOW;
	game->ray->deg_to_rad = 3.14 / 180.0f;
	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_loop(game->graphics->init);
}
