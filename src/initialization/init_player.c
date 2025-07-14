/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:26:15 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:48:28 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	player->x = 0;
	player->y = 0;
	return (player);
}
