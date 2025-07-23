/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:03:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 14:49:11 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#ifndef BONUS

static int	open_wall(t_texture *texture, mlx_context init)
{
	if (open_image(texture->north, init) != 1
		|| open_image(texture->east, init) != 1
		|| open_image(texture->south, init) != 1
		|| open_image(texture->west, init) != 1)
	{
		log_error("Used color instead of image for wall texture.");
		return (1);
	}
	return (0);
}
#else

static int	open_wall(t_texture *texture, mlx_context init)
{
	open_image(texture->north, init);
	open_image(texture->east, init);
	open_image(texture->south, init);
	open_image(texture->west, init);
	return (0);
}
#endif

#ifndef BONUS

static int	open_ground_sky(t_texture *texture, mlx_context init)
{
	if (open_image(texture->sky, init) != 2
		|| open_image(texture->ground, init) != 2)
	{
		log_error("Used image instead of color for ground or sky texture.");
		return (1);
	}
	return (0);
}
#else

static int	open_ground_sky(t_texture *texture, mlx_context init)
{
	open_image(texture->sky, init);
	open_image(texture->ground, init);
	return (0);
}
#endif

int	load_map_texture(t_texture *texture, mlx_context init)
{
	if (open_wall(texture, init))
		return (1);
	if (!texture->north->img || !texture->east->img
		|| !texture->south->img || !texture->west->img)
		return (1);
	if (open_ground_sky(texture, init))
		return (1);
	if (!texture->sky->img || !texture->ground->img)
		return (1);
	texture->battery->path = ft_strdup("assets/battery_2.png");
	open_image(texture->battery, init);
	texture->door->path = ft_strdup("assets/door.png");
	open_image(texture->door, init);
	texture->exit->path = ft_strdup("assets/exit.png");
	open_image(texture->exit, init);
	return (0);
}
