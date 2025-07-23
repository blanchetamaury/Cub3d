/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:39:49 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/21 17:13:39 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player(char c)
{
	int		i;
	char	*str;

	str = "NSEW ";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	fill(char **map, int x, int y, int status)
{
	int	size;
	int	cap;

	size = 0;
	cap = 0;
	ft_stats(map, &size, &cap);
	if (status == 0)
		return (0);
	if (status == 1 && ((y >= size || y < 0 || x >= (int)ft_strlen(map[y])
				|| x < 0) || check_player(map[y][x]) == 0))
		return (0);
	if (y > size || y < 0 || x > (int)ft_strlen(map[y]) || x < 0
		|| (map[y][x] != '0' && map[y][x] != 'P'))
		return (status);
	else
		map[y][x] = 'O';
	status = fill(map, x + 1, y, status);
	status = fill(map, x - 1, y, status);
	status = fill(map, x, y + 1, status);
	status = fill(map, x, y - 1, status);
	return (status);
}

char	**dup_map(char **map)
{
	char	**new;
	int		i;

	new = ft_malloc_h(2);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new = ft_push(new, ft_strdup(map[i]));
		if (new[i] == NULL)
		{
			ft_free_h(new);
			return (NULL);
		}
		i++;
	}
	new = ft_push(new, NULL);
	return (new);
}

int	check_map(t_game *game)
{
	int		size;
	int		cap;
	int		status;
	char	**new_map;

	size = 0;
	cap = 0;
	status = 1;
	game->player->x = find_playerx(game->map->map);
	game->player->y = find_playery(game->map->map);
	if (game->player->x == -1 || game->player->y == -1)
	{
		log_error("No player found in the map");
		return (0);
	}
	ft_stats(game->map->map, &size, &cap);
	new_map = dup_map(game->map->map);
	if (new_map == NULL)
		return (0);
	new_map[game->player->y][game->player->x] = '0';
	status = fill(new_map, game->player->x, game->player->y, status);
	ft_free_h(new_map);
	if (status == 0)
		log_error("Map is not closed.");
	return (status);
}
