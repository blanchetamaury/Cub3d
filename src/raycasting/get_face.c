/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/10 17:00:36 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_face(int side, int step_x, int step_y)
{
	if (side == 0)
	{
		if (step_x < 0)
			return (3);
		else
			return (1);
	}
	else
	{
		if (step_y < 0)
			return (0);
		else
			return (2);
	}
}

int	get_face_height(int side, int step_x, int step_y, t_texture *texture)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0)
		return (texture->north->height);
	if (face == 1)
		return (texture->east->height);
	if (face == 2)
		return (texture->south->height);
	if (face == 3)
		return (texture->west->height);
	return (0);
}

int	get_face_width(int side, int step_x, int step_y, t_texture *texture)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0)
		return (texture->north->width);
	if (face == 1)
		return (texture->east->width);
	if (face == 2)
		return (texture->south->width);
	if (face == 3)
		return (texture->west->width);
	return (0);
}
