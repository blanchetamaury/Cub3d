/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:03:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 21:31:36 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#ifndef BONUS

static int	open_wall(t_image *text, mlx_context init)
{
	if (open_image(&text[NORTH], init) != 1
		|| open_image(&text[EAST], init) != 1
		|| open_image(&text[SOUTH], init) != 1
		|| open_image(&text[WEST], init) != 1)
	{
		log_error("Used color instead of image for wall texture.");
		return (1);
	}
	return (0);
}
#else

static int	open_wall(t_image *text, mlx_context init)
{
	open_image(&text[NORTH], init);
	open_image(&text[EAST], init);
	open_image(&text[SOUTH], init);
	open_image(&text[WEST], init);
	return (0);
}
#endif

#ifndef BONUS

static int	open_ground_sky(t_image *text, mlx_context init)
{
	if (open_image(&text[SKY], init) != 2
		|| open_image(&text[GROUND], init) != 2)
	{
		log_error("Used image instead of color for ground or sky texture.");
		return (1);
	}
	return (0);
}
#else

static int	open_ground_sky(t_image *text, mlx_context init)
{
	open_image(&text[SKY], init);
	open_image(&text[GROUND], init);
	return (0);
}
#endif

int	load_map_texture(t_game *game, mlx_context init)
{
	t_image *text;

	text = game->text;
	if (open_wall(text, init))
		return (1);
	if (!text[NORTH].img || !text[EAST].img
		|| !text[SOUTH].img || !text[WEST].img)
		return (1);
	if (open_ground_sky(text, init))
		return (1);
	if (!text[SKY].img || !text[GROUND].img)
		return (1);
	text[BATTERY].path = ft_strdup("assets/battery_2.png");
	open_image(&text[BATTERY], init);
	text[DOOR].path = ft_strdup("assets/door.png");
	open_image(&text[DOOR], init);
	text[EXIT].path = ft_strdup("assets/exit.png");
	open_image(&text[EXIT], init);
	return (0);
}
