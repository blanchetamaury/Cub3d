/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 14:08:38 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_hud_texture(t_texture *texture, mlx_context init)
{
	int	ignored;

	texture->compass_background = mlx_new_image_from_file(init, "assets/compass_background.png", &ignored, &ignored);
	texture->compass_indicator = mlx_new_image_from_file(init, "assets/compass_indicator.png", &ignored, &ignored);
	texture->hands = mlx_new_image_from_file(init, "assets/hands.png", &ignored, &ignored);
}
