/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:19:44 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/28 09:40:30 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

mlx_image	load(char *name, mlx_context init)
{
	int	ignored;

	return (mlx_new_image_from_file(init, name, &ignored, &ignored));
}

void	load_hud_texture_part3(mlx_image *img, mlx_context init)
{
	img[MAP_T] = load("assets/map_t.png", init);
	img[MAP_B] = load("assets/map_b.png", init);
	img[MAP_L] = load("assets/map_l.png", init);
	img[MAP_R] = load("assets/map_r.png", init);
	img[MAP_P] = load("assets/map_p.png", init);
	img[FLASH_PANEL] = load("assets/flash_panel.png", init);
	img[LED_ON] = load("assets/led_on.png", init);
	img[FLASH_ON] = load("assets/flash_on.png", init);
	img[FLASH_OFF] = load("assets/flash_off.png", init);
	img[CROSSHAIR] = load("assets/crosshair.png", init);
	img[ESCAPED_TITLE] = load("assets/escaped_title.png", init);
	img[RETRY_BUTTON] = load("assets/retry_button.png", init);
	img[RETRY_BUTTON_ACTIVE] = load("assets/retry_button_active.png", init);
	img[MENU_BUTTON] = load("assets/menu_button.png", init);
	img[MENU_BUTTON_ACTIVE] = load("assets/menu_button_active.png", init);
	img[FADE] = load("assets/fade.png", init);
	img[GHOSTED_TITLE] = load("assets/ghosted_title.png", init);
}

void	load_hud_texture_part2(mlx_image *img, mlx_context init)
{
	img[INVENTORY_ICON_SAVE] = load("assets/inventory_icon_save.png",
			init);
	img[INVENTORY_ICON_OPTIONS] = load(
			"assets/inventory_icon_options.png", init);
	img[INVENTORY_ICON_MAP_SELECTED] = load(
			"assets/inventory_icon_map_selected.png", init);
	img[INVENTORY_ICON_CASES_SELECTED] = load(
			"assets/inventory_icon_cases_selected.png", init);
	img[INVENTORY_ICON_SAVE_SELECTED] = load(
			"assets/inventory_icon_save_selected.png", init);
	img[INVENTORY_ICON_OPTIONS_SELECTED] = load(
			"assets/inventory_icon_options_selected.png", init);
	img[Q_ARROW] = load("assets/q_arrow.png", init);
	img[E_ARROW] = load("assets/e_arrow.png", init);
	img[OPTIONS_HEADER] = load("assets/options_header.png", init);
	img[SLIDER_BASE] = load("assets/slider_base.png", init);
	img[SLIDER_SELECTED] = load("assets/slider_selected.png", init);
	img[SWITCH_ON] = load("assets/switch_on.png", init);
	img[SWITCH_OFF] = load("assets/switch_off.png", init);
	img[SWITCH_SELECTED] = load("assets/switch_selected.png", init);
	img[PROGRESS_START] = load("assets/progress_start.png", init);
	img[PROGRESS_CENTER] = load("assets/progress_center.png", init);
	img[PROGRESS_END] = load("assets/progress_end.png", init);
	img[MINIMAP_HEADER] = load("assets/minimap_header.png", init);
	load_hud_texture_part3(img, init);
}

void	load_hud_texture(mlx_image *img, mlx_context init)
{
	img[COMPASS_BACKGROUND] = load("assets/compass_background.png", init);
	img[COMPASS_INDICATOR] = load("assets/compass_indicator.png", init);
	img[HANDS] = load("assets/hands.png", init);
	img[CLOCK_BACKGROUND] = load("assets/clock_background.png", init);
	img[CUB3D_LOGO] = load("assets/cub3d_logo.png", init);
	img[PLAY_BUTTON] = load("assets/play_button.png", init);
	img[ONLINE_BUTTON] = load("assets/online_button.png", init);
	img[OPTION_BUTTON] = load("assets/option_button.png", init);
	img[EXIT_BUTTON] = load("assets/exit_button.png", init);
	img[PLAY_BUTTON_SELECTED] = load("assets/play_button_selected.png", init);
	img[ONLINE_BUTTON_SELECTED] = load("assets/online_button_selected.png",
			init);
	img[OPTION_BUTTON_SELECTED] = load("assets/option_button_selected.png",
			init);
	img[EXIT_BUTTON_SELECTED] = load("assets/exit_button_selected.png", init);
	img[INVENTORY_BACKGROUND] = load("assets/inventory_background.png", init);
	img[INVENTORY_ICON_MAP] = load("assets/inventory_icon_map.png", init);
	img[INVENTORY_ICON_CASES] = load("assets/inventory_icon_cases.png", init);
	load_hud_texture_part2(img, init);
}
