/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:50 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 13:50:22 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_texture(t_game *game)
{
	game->texture->east_path = NULL;
	game->texture->west_path = NULL;
	game->texture->south_path = NULL;
	game->texture->north_path = NULL;
	game->texture->sky.string_color = NULL;
	game->texture->ground.string_color = NULL;
}

static int	check_texture_wall_condition(t_game *game, char *tmp, int count)
{
	if (ft_strncmp(tmp, "EA ", 3) == 0 && game->texture->east_path == NULL
		&& ++count)
		game->texture->east_path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (ft_strncmp(tmp, "WE ", 3) == 0 && game->texture->west_path == NULL
		&& ++count)
		game->texture->west_path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (ft_strncmp(tmp, "SO ", 3) == 0 && game->texture->south_path == NULL
		&& ++count)
		game->texture->south_path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (ft_strncmp(tmp, "NO ", 3) == 0 && game->texture->north_path == NULL
		&& ++count)
		game->texture->north_path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (ft_strncmp(tmp, "F ", 2) == 0
		&& game->texture->ground.string_color == NULL && ++count)
		game->texture->ground.string_color = ft_substr(tmp, 2,
				ft_strlen(tmp) - 3);
	else if (ft_strncmp(tmp, "C ", 2) == 0
		&& game->texture->sky.string_color == NULL && ++count)
		game->texture->sky.string_color = ft_substr(tmp, 2, ft_strlen(tmp) - 3);
	return (count);
}

static int	check_texture_all(t_game *game)
{
	char	*tmp;
	int		count;

	count = 0;
	init_texture(game);
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL && count < 6)
	{
		count = check_texture_wall_condition(game, tmp, count);
		free(tmp);
		if (count < 6)
			tmp = get_next_line(game->map->fd_map);
	}
	if (check_ground_and_sky(game, count) == 0)
		return (0);
	return (1);
}

int	check_texture(t_game *game)
{
	return (check_texture_all(game));
}
