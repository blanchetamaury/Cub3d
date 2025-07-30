/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:06:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/30 15:10:26 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_current_ghost_texture(t_game *game)
{
	if (game->graphics->frame % 20 < 5)
		return (GHOST_FLY0);
	if (game->graphics->frame % 20 < 10)
		return (GHOST_FLY1);
	if (game->graphics->frame % 20 < 15)
		return (GHOST_FLY2);
	if (game->graphics->frame % 20 < 20)
		return (GHOST_FLY3);
	return (GHOST_FLY0);
}

int	verif_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	log_error("Invalid color format. Expected 3 components (R,G,B).");
	return (0);
}
