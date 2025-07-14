/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subscribe_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:02:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:30:01 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	subscribe_events(t_game *game)
{
	subscribe_keydown(game->graphics, game->events);
	subscribe_keyup(game->graphics, game->events);
	subscribe_mouseup(game->graphics, game);
	subscribe_window(game->graphics, game->events);
}
