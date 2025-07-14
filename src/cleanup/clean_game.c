/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:22:35 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 13:55:49 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_game(t_game *game)
{
	clean_window_info(game);
	clean_texture(game->texture, game->graphics->init);
	clean_graphics(game->graphics);
	clean_map(game->map);
	clean_player(game->player);
	clean_raycasting(game->ray);
	free(game);
}
