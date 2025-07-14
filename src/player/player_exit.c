/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:08:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/14 11:15:01 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_exit(t_game *game)
{
	if (game->events->exit)
		mlx_loop_end(game->graphics->init);
}
