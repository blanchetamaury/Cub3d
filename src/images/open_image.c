/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:29 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/09 17:57:33 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_image(t_image *image, mlx_context init)
{
	if (image->path == NULL)
		return ;
	image->img = mlx_new_image_from_file(init, image->path, &image->width, &image->height);
}