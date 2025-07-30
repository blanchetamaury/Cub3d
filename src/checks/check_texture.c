/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:21:50 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/30 13:20:00 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_texture_wall_condition(t_image *text, char *tmp, int count)
{
	int i;

	i = -1;
	if (!ft_strncmp(tmp, "EA ", 3) && text[EAST].path == NULL && ++count)
		text[EAST].path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (!ft_strncmp(tmp, "WE ", 3) && text[WEST].path == NULL && ++count)
		text[WEST].path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (!ft_strncmp(tmp, "SO ", 3) && text[SOUTH].path == NULL && ++count)
		text[SOUTH].path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (!ft_strncmp(tmp, "NO ", 3) && text[NORTH].path == NULL && ++count)
		text[NORTH].path = ft_substr(tmp, 3, ft_strlen(tmp) - 4);
	else if (!ft_strncmp(tmp, "F ", 2) && text[GROUND].path == NULL && ++count)
		text[GROUND].path = ft_substr(tmp, 2, ft_strlen(tmp) - 3);
	else if (!ft_strncmp(tmp, "C ", 2) && text[SKY].path == NULL && ++count)
		text[SKY].path = ft_substr(tmp, 2, ft_strlen(tmp) - 3);
	else
		while (tmp[++i])
			if (ft_isprint(tmp[i]) && ++count)
				break ;
	return (count);
}

static int	check_texture_all(t_game *game)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = get_next_line(game->map->fd_map);
	while (tmp != NULL && count < 6)
	{
		count = check_texture_wall_condition(game->text, tmp, count);
		free(tmp);
		if (count < 6)
			tmp = get_next_line(game->map->fd_map);
	}
	if (count != 6)
	{
		log_error("A texture is missing. "
			"All of these are required : NO, SO, WE, EA, F, C");
		return (0);
	}
	return (1);
}

int	check_texture(t_game *game)
{
	return (check_texture_all(game));
}
