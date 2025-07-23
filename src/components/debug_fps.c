/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:31:04 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 15:45:55 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	debug_fps(t_game *game)
{
	char	*tmp;
	char	*fps_str;

	tmp = ft_itoa(min(game->graphics->fps, game->graphics->max_fps));
	fps_str = ft_strjoin("FPS: ", tmp);
	free(tmp);
	mlx_string_put(game->graphics->init, game->graphics->window,
		WIDTH_WINDOW - 150, 20, color(0xFFEA00FF), fps_str);
	free(fps_str);
}
