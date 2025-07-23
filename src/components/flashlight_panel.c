/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flashlight_panel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:18:16 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 20:20:15 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	flashlight_panel(t_game *game)
{
	int	i;

	mlx_put_image_to_window(game->graphics->init, game->graphics->window,
		game->img[FLASH_PANEL], WIDTH_WINDOW - 154,
		HEIGHT_WINDOW - 246);
	if (!game->events->flashlight)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[FLASH_ON], WIDTH_WINDOW - 82,
			HEIGHT_WINDOW - 74);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[FLASH_OFF], WIDTH_WINDOW - 82,
			HEIGHT_WINDOW - 74);
	i = 1;
	while (i <= 6 && game->player->battery > (i * 600) - 600)
	{
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->img[LED_ON], 1164, 734 - (i - 1) * 18.5f);
		i++;
	}
}
