/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:15:35 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/17 10:20:53 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	progress(int	value, int x, int y, t_game	*game)
{
	int	i;

	if (value > 0)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->progress_start, x, y);
	i = 1;
	while (i <= 4)
	{
		if (value > i)
			mlx_put_image_to_window(game->graphics->init, game->graphics->window,
				game->texture->progress_center, x + 56 + (60 * (i - 1)), y);
		i++;
	}
	if (value > 5)
		mlx_put_image_to_window(game->graphics->init, game->graphics->window,
			game->texture->progress_end, x + 56 + (60 * 4), y);
}