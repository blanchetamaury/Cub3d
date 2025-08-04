/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:30:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/08/04 16:39:48 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_char(char c)
{
	char	*str;
	int		i;

	str = "NESW";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	check_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (check_char(game->map->map[i][j]) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (1);
}

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
	if (check_player(game) == 1)
		return (log_error("Too many player in map."));
	check_door(game);
	init_player_pos(game);
	ft_stats(game->map->map, &game->map->size, &game->map->cap);
	return (0);
}
