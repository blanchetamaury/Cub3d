/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animated_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:01:04 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/28 09:42:39 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	load_ghost_fly_animation(t_game	*game)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (i < 4)
	{
		tmp = ft_itoa(i);
		path = ft_strjoin("assets/ghost_fly", tmp);
		free(tmp);
		tmp = ft_strjoin(path, ".png");
		free(path);
		game->text[GHOST_FLY0 + i].path = tmp;
		open_image(&game->text[GHOST_FLY0 + i], game->graphics->init);
		i++;
	}
}

void	load_animation_texture(t_game *game)
{
	load_ghost_fly_animation(game);
}
