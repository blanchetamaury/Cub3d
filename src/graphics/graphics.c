/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:05:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/10 10:03:12 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	graphic(t_game *game)
{
	mlx_add_loop_hook(game->graphics->init, render, game);
	mlx_loop(game->graphics->init);
}