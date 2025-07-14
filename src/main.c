/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 11:31:40 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (log_error("Missing map files arguments.") - 27);
	else if (argc > 2)
		log_warn("Only one map arguments is supported. Using the first.");
	game = init_game();
	if (game == NULL)
		return (log_error("Memory allocation failed.") - 24);
	if (check_file_map(argv, game) || load_map_texture(game->texture,
			game->graphics->init))
	{
		clean_game(game);
		return (0);
	}
	load_hud_texture(game->texture, game->graphics->init);
	create_window(game->graphics);
	subscribe_events(game);
	graphic(game);
	clean_game(game);
}
