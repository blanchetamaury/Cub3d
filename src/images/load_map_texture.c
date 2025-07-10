/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:03:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 18:05:19 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	load_map_texture(t_texture *texture, mlx_context init)
{
	open_image(texture->north, init);
	if (!texture->north->img)
		return (1);
	open_image(texture->east, init);
	if (!texture->east->img)
		return (1);
	open_image(texture->south, init);
	if (!texture->south->img)
		return (1);
	open_image(texture->west, init);
	if (!texture->west->img)
		return (1);
	open_image(texture->sky, init);
	if (!texture->sky->img)
		return (1);
	open_image(texture->ground, init);
	if (!texture->ground->img)
		return (1);
	return (0);
}