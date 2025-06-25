/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:30:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 13:17:48 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_name_map(char *name, t_game *game)
{
	int			len;
	int			pos;
	const char	tab[4] = ".cub";

	pos = 3;
	len = ft_strlen(name) - 1;
	while (len > 0 && pos > 0)
	{
		if (name[len] != tab[pos])
			return (1);
		len--;
		pos--;
	}
	game->map->name = name;
	return (0);
}

int	check_file_map(char **argv, t_game *game)
{
	if (check_name_map(argv[1], game) == 1)
		return (0);
	game->map->fd_map = open(game->map->name, O_RDONLY);
	if (game->map->fd_map == -1)
		return (0);
	if (check_texture(game) == 0)
		return (0);
	return (1);
}
