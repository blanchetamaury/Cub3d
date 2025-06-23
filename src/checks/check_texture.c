/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:50 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/23 16:13:24 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int is_whitespace(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || (str[i] <= 9 || str[i] >= 13))
			return (0);
		i++;
	}
	return (1);
}

static int check_texture_wall(t_game *game)
{
	char    *tmp;
	int     i;
	
	i = 0;
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp, "EA", 2) == 0)
		{
			game->texture->east_path = ft_strdup(&tmp[3]);
			printf("ea = [%s]\n", game->texture->east_path);
		}
		else if (ft_strncmp(tmp, "WE", 2) == 0)
		{
			game->texture->west_path = ft_strdup(&tmp[3]);
			printf("we = [%s]\n", game->texture->west_path);
		}
		else if (ft_strncmp(tmp, "SO", 2) == 0)
		{
			game->texture->south_path = ft_strdup(&tmp[3]);
			printf("so = [%s]\n", game->texture->south_path);
		}
		else if (ft_strncmp(tmp, "NO", 2) == 0)
		{
			game->texture->north_path = ft_strdup(&tmp[3]);
			printf("no = [%s]\n", game->texture->north_path);
		}
		else if (is_whitespace(tmp) == 0)
		{
			free(tmp);
			close(game->map->fd_map);
			free(game->texture->east_path);
			free(game->texture->west_path);
			free(game->texture->south_path);
			free(game->texture->north_path);
			return (0);
		}
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
	free(game->texture->east_path);
	free(game->texture->west_path);
	free(game->texture->south_path);
	free(game->texture->north_path);
	return (1);
}


int check_texture(t_game *game)
{
	if (check_texture_wall(game) == 0)
		return (0);
	return (1);
}