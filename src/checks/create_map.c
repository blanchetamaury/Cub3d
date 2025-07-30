/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:09:04 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/30 15:08:47 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_line_map(char *str)
{
	int		i;
	int		j;
	char	*find;

	i = 0;
	if (ft_strlen(str) == 1 && str[0] == '\n')
		return (2);
	if (is_bonus())
		find = " 10NSEWPQ\n";
	else
		find = " 10NSEW\n";
	while (str[i])
	{
		j = -1;
		while (find[++j])
			if (find[j] == str[i])
				break ;
		if (j >= 10 && is_bonus())
			return (0);
		else if (j >= 8 && !is_bonus())
			return (0);
		i++;
	}
	return (1);
}

static void	close_file(t_game *game, char *tmp)
{
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
}

static int	write_map(t_game *game, int *status)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL)
	{
		if (tmp != NULL && check_line_map(tmp) == 0)
		{
			*status = 0;
			log_error("Invalid character found in the map");
			break ;
		}
		if (tmp != NULL && ft_strlen(tmp) > 1)
		{
			game->map->map = ft_push(game->map->map, ft_strtrim(tmp, "\n"));
			i++;
		}
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
	game->map->map = ft_push(game->map->map, NULL);
	close_file(game, tmp);
	return (i);
}

static int	create_map(t_game *game, int status_line, int status)
{
	char	*tmp;

	game->map->map = ft_malloc_h(2);
	if (game->map->map == NULL)
		return (close(game->map->fd_map));
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL)
	{
		status_line = check_line_map(tmp);
		if (status_line == 0)
		{
			free(tmp);
			log_error("Too many texture found. "
				"All of these are required : NO, SO, WE, EA, F, C");
			return (0);
		}
		else if (status_line)
			break ;
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
	free(tmp);
	if (write_map(game, &status) == 0 || status == 0)
		return (0);
	return (1);
}

int	get_map(t_game *game)
{
	if (create_map(game, 0, 1) == 0)
	{
		log_error("Map not found");
		return (0);
	}
	return (1);
}
