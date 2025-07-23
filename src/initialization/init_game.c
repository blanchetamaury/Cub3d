/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:12:41 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 19:59:27 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game->texture = init_texture();
	game->graphics = init_graphics();
	game->map = init_map();
	game->img[RENDER] = mlx_new_image(game->graphics->init,
			WIDTH_WINDOW, HEIGHT_WINDOW);
	game->img[RENDER_TMP] = mlx_new_image(game->graphics->init,
			WIDTH_WINDOW, HEIGHT_WINDOW);
	game->player = init_player();
	game->ray = init_raycasting();
	game->events = init_events();
	return (game);
}
