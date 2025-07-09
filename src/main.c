/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/09 10:48:51 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game *game;

	if (argc < 2)
		return (log_error("Missing map files arguments.") - 27);
	else if (argc > 2)
		log_warn("Only one map arguments is supported. Using the first.");
	game = init_game();
	if (game == NULL)
		return (log_error("Memory allocation failed.") - 24);
	if (check_file_map(argv, game))
	{
		clean_game(game);
		return (0);
	}
	printf("EA = [%s]\n", game->texture->east_path);
	printf("WE = [%s]\n", game->texture->west_path);
	printf("SO = [%s]\n", game->texture->south_path);
	printf("NO = [%s]\n", game->texture->north_path);
	//printf("sky R = %d | G = %d | B = %d\n", game->texture->sky->r, game->texture->sky->g, game->texture->sky->b);
	//printf("ground R = %d | G = %d | B = %d\n", game->texture->ground->r, game->texture->ground->g, game->texture->ground->b);
	create_window(game->graphics);
	subscribe_events(game->graphics, game->events);
	graphic(game);
	clean_game(game);
}
