/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:16:48 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 14:58:19 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	clean_hud(t_texture *texture, mlx_context init)
{
	if (texture->compass_background)
		mlx_destroy_image(init, texture->compass_background);
	if (texture->compass_indicator)
		mlx_destroy_image(init, texture->compass_indicator);
	if (texture->hands)
		mlx_destroy_image(init, texture->hands);
	if (texture->clock_background)
		mlx_destroy_image(init, texture->clock_background);
}

void	clean_texture(t_texture *texture, mlx_context init)
{
	clean_image(texture->north, init);
	clean_image(texture->east, init);
	clean_image(texture->south, init);
	clean_image(texture->west, init);
	mlx_destroy_image(init, texture->render);
	clean_hud(texture, init);
	clean_color(texture->sky);
	clean_color(texture->ground);
	free(texture);
}