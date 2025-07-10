/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 18:14:51 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	graphic(t_game *game)
{
	game->size_x = 0;
	game->size_y = 0;
	game->texture->east = mlx_new_image_from_file(game->graphics->init, game->texture->east_path, &game->size_x, &game->size_y);
	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_loop(game->graphics->init);

	mlx_destroy_image(game->graphics->init, game->map->img);
	mlx_destroy_image(game->graphics->init, game->texture->east);
	mlx_destroy_window(game->graphics->init, game->graphics->window);
	mlx_destroy_context(game->graphics->init);
}