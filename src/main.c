/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:06:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/23 11:18:31 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_verif_name_map(char *name, t_game *game)
{
	int len;
	int pos;
	const char tab[4] = ".cub";

	pos = 3;
	len = ft_strlen(name) - 1;
	while (len > 0 &&  pos > 0)
	{
		if (name[len] != tab[pos])
			return (1);
		len--;
		pos--;
	}
	game->map->name = name;
	return (0);
}

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
	if (ft_verif_name_map(argv[1], game) == 1)
	{
		write(2, "error\n", 6);
		exit (1);
	}
	printf("argv = %s\n", game->map->name);
}