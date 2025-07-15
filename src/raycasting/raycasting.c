/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 14:24:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_game *game)
{
	mlx_color	color[WIDTH_WINDOW * HEIGHT_WINDOW];

	raycasting_floor(game);
	raycasting_wall(game);
	//raycasting_sprite(game);
	mlx_get_image_region(game->graphics->init, game->texture->render, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW, color);
	mlx_set_image_region(game->graphics->init, game->texture->render_tmp, 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW, color);
}
