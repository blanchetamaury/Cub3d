/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:16:48 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/24 14:36:11 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	clean_img(mlx_context init, mlx_image img)
{
	if (img)
		mlx_destroy_image(init, img);
}

void	clean_texture(t_image *text, mlx_image *img, mlx_context init)
{
	int	i;

	i = 0;
	while (i < SIZE_LIST_IMG)
	{
		clean_img(init, img[i]);
		i++;
	}
	i = 0;
	while (i < SIZE_LIST_TEXT)
	{
		clean_image(&text[i], init);
		i++;
	}
}
