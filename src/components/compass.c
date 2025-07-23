/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:23:25 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:19:36 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	compass(t_game *game)
{
	mlx_put_image_to_window(
		game->graphics->init, game->graphics->window,
		game->img[COMPASS_BACKGROUND],
		WIDTH_WINDOW - 160 - 24,
		0
		);
	mlx_put_transformed_image_to_window(
		game->graphics->init, game->graphics->window,
		game->img[COMPASS_INDICATOR],
		WIDTH_WINDOW - 96 - 54,
		55,
		1,
		1,
		game->player->angle + 90
		);
}
