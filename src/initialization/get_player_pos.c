/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:12:42 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/01 11:13:12 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_playery(char **map)
{
	int		x;
	int		y;
	char	*str;
	int		len;

	y = 0;
	str = "NSEW";
	len = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			len = 0;
			while (str[len])
			{
				if (str[len] == map[y][x])
					return (y);
				len++;
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	find_playerx(char **map)
{
	int		x;
	int		y;
	char	*str;
	int		len;

	y = 0;
	str = "NSEW";
	len = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			len = 0;
			while (str[len])
			{
				if (str[len] == map[y][x])
					return (x);
				len++;
			}
			x++;
		}
		y++;
	}
	return (-1);
}
