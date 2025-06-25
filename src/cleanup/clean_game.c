/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:22:35 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 13:23:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture(t_game *game)
{
	free(game->texture->east_path);
	free(game->texture->west_path);
	free(game->texture->south_path);
	free(game->texture->north_path);
	free(game->texture->sky.string_color);
	free(game->texture->ground.string_color);
}
