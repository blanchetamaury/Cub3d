/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 10:31:18 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		write(2, "error\n", 6);
		exit(1);
	}
	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (1);
	game->map = malloc(sizeof(t_map));
	game->texture = malloc(sizeof(t_texture));
	if (game->map == NULL)
	{
		free(game);
		return (1);
	}
	if (check_file_map(argv, game) == 0)
	{
		write(2, "error\n", 6);
		free(game->texture);
		free(game->map);
		free(game);
		return (0);
	}
	printf("argv = %s\n", game->map->name);
	free(game->texture);
	free(game->map);
	free(game);
}