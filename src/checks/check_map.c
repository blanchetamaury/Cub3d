/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:30:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/07 09:57:03 by rgodet           ###   ########.fr       */
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
		return (log_error("Invalid format. Only .cub format supported."));
	game->map->fd_map = open(game->map->name, O_RDONLY);
	if (game->map->fd_map == -1)
		return (log_error("Failed to open file. Have you right permission ?"));
	if (check_texture(game) == 0)
		return (1);
	if (get_map(game) == 0)
		return (1);
	if (check_map(game) == 0)
		return (1);
	return (0);
}
