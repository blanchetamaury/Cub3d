/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:16:48 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 14:15:33 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	clean_img(mlx_context init, mlx_image img)
{
	if (img)
		mlx_destroy_image(init, img);
}

static void	clean_hud(t_texture *texture, mlx_context init)
{
	clean_img(init, texture->compass_background);
	clean_img(init, texture->compass_indicator);
	clean_img(init, texture->hands);
	clean_img(init, texture->clock_background);
	clean_img(init, texture->cub3d_logo);
	clean_img(init, texture->play_button);
	clean_img(init, texture->online_button);
	clean_img(init, texture->option_button);
	clean_img(init, texture->exit_button);
	clean_img(init, texture->play_button_selected);
	clean_img(init, texture->online_button_selected);
	clean_img(init, texture->option_button_selected);
	clean_img(init, texture->exit_button_selected);
	clean_img(init, texture->inventory_background);
}

void	clean_texture(t_texture *texture, mlx_context init)
{
	clean_image(texture->north, init);
	clean_image(texture->east, init);
	clean_image(texture->south, init);
	clean_image(texture->west, init);
	clean_image(texture->sky, init);
	clean_image(texture->ground, init);
	mlx_destroy_image(init, texture->render);
	mlx_destroy_image(init, texture->render_tmp);
	clean_hud(texture, init);
	free(texture);
}
