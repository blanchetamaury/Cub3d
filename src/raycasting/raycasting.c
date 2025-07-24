/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:16:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/24 09:34:52 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting(t_game *game)
{
	static mlx_color	color[HEIGHT_WINDOW * WIDTH_WINDOW];
	static float		z_buffer[WIDTH_WINDOW];
	int					status;

	status = 0;
	raycasting_floor(game);
	raycasting_wall(game, &status, z_buffer);
	raycasting_sprite(game, status, z_buffer);
	mlx_get_image_region(game->graphics->init, game->img[RENDER], 0,
		0, WIDTH_WINDOW, HEIGHT_WINDOW, color);
	mlx_set_image_region(game->graphics->init, game->img[RENDER_TMP], 0,
		0, WIDTH_WINDOW, HEIGHT_WINDOW, color);
}
