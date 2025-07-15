/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:49:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image	load(char *name, mlx_context init)
{
	int	ignored;

	return (mlx_new_image_from_file(init, name, &ignored, &ignored));
}

void	load_hud_texture(t_texture *texture, mlx_context init)
{
	texture->compass_background = load("assets/compass_background.png", init);
	texture->compass_indicator = load("assets/compass_indicator.png", init);
	texture->hands = load("assets/hands.png", init);
	texture->clock_background = load("assets/clock_background.png", init);
	texture->cub3d_logo = load("assets/cub3d_logo.png", init);
	texture->play_button = load("assets/play_button.png", init);
	texture->online_button = load("assets/online_button.png", init);
	texture->option_button = load("assets/option_button.png", init);
	texture->exit_button = load("assets/exit_button.png", init);
	texture->play_button_selected = load(
			"assets/play_button_selected.png", init);
	texture->online_button_selected = load(
			"assets/online_button_selected.png", init);
	texture->option_button_selected = load(
			"assets/option_button_selected.png", init);
	texture->exit_button_selected = load(
			"assets/exit_button_selected.png", init);
	texture->inventory_background = load(
			"assets/inventory_background.png", init);
}
