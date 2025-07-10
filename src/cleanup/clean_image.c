/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:54:11 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 09:38:30 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_image(t_image *image, mlx_context init)
{
	if (init && image->img)
		mlx_destroy_image(init, image->img);
	if (image->path)
		free(image->path);
	free(image);
}