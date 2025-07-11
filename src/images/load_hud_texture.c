/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/10 14:58:48 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_hud_texture(t_texture *texture, mlx_context init)
{
	int	ignored;

	texture->compass_background = mlx_new_image_from_file(init, "assets/compass_background.png", &ignored, &ignored);
	texture->compass_indicator = mlx_new_image_from_file(init, "assets/compass_indicator.png", &ignored, &ignored);
	texture->hands = mlx_new_image_from_file(init, "assets/hands.png", &ignored, &ignored);
	texture->clock_background = mlx_new_image_from_file(init, "assets/clock_background.png", &ignored, &ignored);
	texture->cub3d_logo = mlx_new_image_from_file(init, "assets/cub3d_logo.png", &ignored, &ignored);
	texture->play_button = mlx_new_image_from_file(init, "assets/play_button.png", &ignored, &ignored);
	texture->online_button = mlx_new_image_from_file(init, "assets/online_button.png", &ignored, &ignored);
	texture->option_button = mlx_new_image_from_file(init, "assets/option_button.png", &ignored, &ignored);
	texture->exit_button = mlx_new_image_from_file(init, "assets/exit_button.png", &ignored, &ignored);
	texture->play_button_selected = mlx_new_image_from_file(init, "assets/play_button_selected.png", &ignored, &ignored);
	texture->online_button_selected = mlx_new_image_from_file(init, "assets/online_button_selected.png", &ignored, &ignored);
	texture->option_button_selected = mlx_new_image_from_file(init, "assets/option_button_selected.png", &ignored, &ignored);
	texture->exit_button_selected = mlx_new_image_from_file(init, "assets/exit_button_selected.png", &ignored, &ignored);
}
