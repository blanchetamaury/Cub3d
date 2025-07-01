/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/30 16:18:25 by amblanch         ###   ########.fr       */
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
	if (game->map == NULL)
	{
		free(game);
		return (1);
	}
	game->texture = malloc(sizeof(t_texture));
	game->player = malloc(sizeof(t_player));
	game->map->map = NULL;
	if (check_file_map(argv, game) == 0)
	{
		write(2, "error\n", 6);
		if (game->map->map != NULL)
			ft_free_h(game->map->map);
		free_texture(game);
		free(game->texture);
		free(game->map);
		free(game->player);
		free(game);
		return (0);
	}
	printf("EA = [%s]\n", game->texture->east_path);
	printf("WE = [%s]\n", game->texture->west_path);
	printf("SO = [%s]\n", game->texture->south_path);
	printf("NO = [%s]\n", game->texture->north_path);
	printf("sky R = %d | G = %d | B = %d\n", game->texture->sky.r, game->texture->sky.g, game->texture->sky.b);
	printf("ground R = %d | G = %d | B = %d\n", game->texture->ground.r, game->texture->ground.g, game->texture->ground.b);
	ft_free_h(game->map->map);
	free_texture(game);
	free(game->texture);
	free(game->map);
	free(game->player);
	free(game);
}
