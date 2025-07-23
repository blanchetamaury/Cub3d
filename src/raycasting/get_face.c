/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_face.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/23 21:23:47 by amblanch         ###   ########.fr       */
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

int	get_face_height(int side, int step_x, int step_y, t_image *text)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0)
		return (text[NORTH].height);
	if (face == 1)
		return (text[EAST].height);
	if (face == 2)
		return (text[SOUTH].height);
	if (face == 3)
		return (text[WEST].height);
	return (0);
}

int	get_face_width(int side, int step_x, int step_y, t_image *text)
{
	int	face;

	face = get_face(side, step_x, step_y);
	if (face == 0)
		return (text[NORTH].width);
	if (face == 1)
		return (text[EAST].width);
	if (face == 2)
		return (text[SOUTH].width);
	if (face == 3)
		return (text[WEST].width);
	return (0);
}
