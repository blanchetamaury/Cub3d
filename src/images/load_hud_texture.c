/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/17 16:21:46 by rgodet           ###   ########.fr       */
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
	texture->inventory_icon_map = load(
			"assets/inventory_icon_map.png", init);
	texture->inventory_icon_cases = load(
			"assets/inventory_icon_cases.png", init);
	texture->inventory_icon_save = load(
			"assets/inventory_icon_save.png", init);
	texture->inventory_icon_options = load(
			"assets/inventory_icon_options.png", init);
	texture->inventory_icon_map_selected = load(
			"assets/inventory_icon_map_selected.png", init);
	texture->inventory_icon_cases_selected = load(
			"assets/inventory_icon_cases_selected.png", init);
	texture->inventory_icon_save_selected = load(
			"assets/inventory_icon_save_selected.png", init);
	texture->inventory_icon_options_selected = load(
			"assets/inventory_icon_options_selected.png", init);
	texture->q_arrow = load("assets/q_arrow.png", init);
	texture->e_arrow = load("assets/e_arrow.png", init);
	texture->options_header = load("assets/options_header.png", init);
	texture->slider_base = load("assets/slider_base.png", init);
	texture->slider_selected = load("assets/slider_selected.png", init);
	texture->switch_on = load("assets/switch_on.png", init);
	texture->switch_off = load("assets/switch_off.png", init);
	texture->switch_selected = load("assets/switch_selected.png", init);
	texture->progress_start = load("assets/progress_start.png", init);
	texture->progress_center = load("assets/progress_center.png", init);
	texture->progress_end = load("assets/progress_end.png", init);
	texture->minimap_header = load("assets/minimap_header.png", init);
	texture->map_t = load("assets/map_t.png", init);
	texture->map_b = load("assets/map_b.png", init);
	texture->map_l = load("assets/map_l.png", init);
	texture->map_r = load("assets/map_r.png", init);
	texture->map_p = load("assets/map_p.png", init);
}
