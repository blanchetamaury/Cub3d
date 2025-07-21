/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:19:15 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 13:20:31 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	switch_view(t_game *game, int is_on, int x, int y)
{
	if (is_on)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->switch_on, x, y);
	else
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->switch_off, x, y);
}