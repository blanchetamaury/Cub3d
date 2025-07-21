/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:16:48 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 17:14:55 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	clean_img(mlx_context init, mlx_image img)
{
	if (img)
		mlx_destroy_image(init, img);
}

static void	clean_hud_game(t_texture *texture, mlx_context init)
{
	clean_img(init, texture->compass_background);
	clean_img(init, texture->compass_indicator);
	clean_img(init, texture->hands);
	clean_img(init, texture->clock_background);
	clean_img(init, texture->inventory_icon_map);
	clean_img(init, texture->inventory_icon_cases);
	clean_img(init, texture->inventory_icon_save);
	clean_img(init, texture->inventory_icon_options);
	clean_img(init, texture->inventory_icon_map_selected);
	clean_img(init, texture->inventory_icon_cases_selected);
	clean_img(init, texture->inventory_icon_save_selected);
	clean_img(init, texture->inventory_icon_options_selected);
	clean_img(init, texture->q_arrow);
	clean_img(init, texture->e_arrow);
	clean_img(init, texture->map_t);
	clean_img(init, texture->map_b);
	clean_img(init, texture->map_l);
	clean_img(init, texture->map_r);
	clean_img(init, texture->map_p);
	clean_img(init, texture->flash_panel);
	clean_img(init, texture->led_on);
	clean_img(init, texture->flash_on);
	clean_img(init, texture->flash_off);
	clean_img(init, texture->crosshair);
}

static void	clean_hud(t_texture *texture, mlx_context init)
{
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
	clean_img(init, texture->minimap_header);
	clean_img(init, texture->options_header);
	clean_img(init, texture->slider_base);
	clean_img(init, texture->slider_selected);
	clean_img(init, texture->switch_on);
	clean_img(init, texture->switch_off);
	clean_img(init, texture->switch_selected);
	clean_img(init, texture->progress_start);
	clean_img(init, texture->progress_center);
	clean_img(init, texture->progress_end);
	clean_hud_game(texture, init);
}

void	clean_texture(t_texture *texture, mlx_context init)
{
	clean_image(texture->north, init);
	clean_image(texture->east, init);
	clean_image(texture->south, init);
	clean_image(texture->west, init);
	clean_image(texture->sky, init);
	clean_image(texture->ground, init);
	clean_image(texture->battery, init);
	clean_image(texture->door, init);
	mlx_destroy_image(init, texture->render);
	mlx_destroy_image(init, texture->render_tmp);
	clean_hud(texture, init);
	free(texture);
}
