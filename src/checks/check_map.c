/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:30:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/30 12:34:47 by amblanch         ###   ########.fr       */
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

static int	check_line_map(char *str)
{
	int i;
	int j;
	char *find;

	i = 0;
	j = 0;
	find = " 10NSEW\n";
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (find[j] == str[i])
				break ;
			j++;
		}
		if (j >= 8)
			return (0);
		i++;
	}
	return (1);
}

static int create_map(t_game *game)
{
	int		i;
	int		status;
	char	*tmp;

	status = 1;
	i = 0;
	game->map->map = ft_malloc_h(2);
	if (game->map->map == NULL)
	{
		close (game->map->fd_map);
		return (0);
	}
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL)
	{
		if (check_line_map(tmp) == 1)
			break ;
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
	free(tmp);
	while (tmp != NULL)
	{
		tmp = get_next_line(game->map->fd_map);
		if (tmp != NULL && check_line_map(tmp) == 0)
		{
			status = 0;
			break ;
		}
		if (tmp != NULL && ft_strlen(tmp) > 1)
		{
			game->map->map = ft_push(game->map->map, ft_strtrim(tmp, "\n"));
			i++;
		}
		free(tmp);
	}
	game->map->map = ft_push(game->map->map, NULL);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(game->map->fd_map);
	}
	close (game->map->fd_map);
	if (i == 0 || status == 0)
		return (0);
	return (1);
}

static int get_map(t_game *game)
{
	if (create_map(game) == 0)
		return (0);
	return (1);
}

int	check_file_map(char **argv, t_game *game)
{
	if (check_name_map(argv[1], game) == 1)
		return (0);
	game->map->fd_map = open(game->map->name, O_RDONLY);
	if (game->map->fd_map == -1)
		return (0);
	if (check_texture(game) == 0)
	{
		close(game->map->fd_map);
		return (0);
	}
	if (get_map(game) == 0)
	{
		close(game->map->fd_map);
		return (0);
	}
	close(game->map->fd_map);
	return (1);
}
