/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:06:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/25 10:06:14 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_current_ghost_texture(t_game *game)
{
	if (game->graphics->frame % 20 < 5)
		return (GHOST_FLY0);
	if (game->graphics->frame % 20 < 10)
		return (GHOST_FLY1);
	if (game->graphics->frame % 20 < 15)
		return (GHOST_FLY2);
	if (game->graphics->frame % 20 < 20)
		return (GHOST_FLY3);
	return (GHOST_FLY0);
}
