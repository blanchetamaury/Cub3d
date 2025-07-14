/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:23:25 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:27:32 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	compass(t_game *game)
{
	mlx_put_image_to_window(
		game->graphics->init, game->graphics->window,
		game->texture->compass_background,
		width_window - 105 - 20,
		20
		);
	mlx_put_transformed_image_to_window(
		game->graphics->init, game->graphics->window,
		game->texture->compass_indicator,
		width_window - 105 - 20,
		20,
		1,
		1,
		game->player->angle + 90
		);
}
