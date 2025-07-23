/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:16:48 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 21:51:42 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	clean_img(mlx_context init, mlx_image img)
{
	if (img)
		mlx_destroy_image(init, img);
}

static void	clean_hud_game(mlx_image *img, mlx_context init)
{
	clean_img(init, img[COMPASS_BACKGROUND]);
	clean_img(init, img[COMPASS_INDICATOR]);
	clean_img(init, img[HANDS]);
	clean_img(init, img[CLOCK_BACKGROUND]);
	clean_img(init, img[INVENTORY_ICON_MAP]);
	clean_img(init, img[INVENTORY_ICON_CASES]);
	clean_img(init, img[INVENTORY_ICON_SAVE]);
	clean_img(init, img[INVENTORY_ICON_OPTIONS]);
	clean_img(init, img[INVENTORY_ICON_MAP_SELECTED]);
	clean_img(init, img[INVENTORY_ICON_CASES_SELECTED]);
	clean_img(init, img[INVENTORY_ICON_SAVE_SELECTED]);
	clean_img(init, img[INVENTORY_ICON_OPTIONS_SELECTED]);
	clean_img(init, img[Q_ARROW]);
	clean_img(init, img[E_ARROW]);
	clean_img(init, img[MAP_T]);
	clean_img(init, img[MAP_B]);
	clean_img(init, img[MAP_L]);
	clean_img(init, img[MAP_R]);
	clean_img(init, img[MAP_P]);
	clean_img(init, img[FLASH_PANEL]);
	clean_img(init, img[LED_ON]);
	clean_img(init, img[FLASH_ON]);
	clean_img(init, img[FLASH_OFF]);
	clean_img(init, img[CROSSHAIR]);
}

static void	clean_hud(mlx_image *img, mlx_context init)
{
	clean_img(init, img[CUB3D_LOGO]);
	clean_img(init, img[PLAY_BUTTON]);
	clean_img(init, img[ONLINE_BUTTON]);
	clean_img(init, img[OPTION_BUTTON]);
	clean_img(init, img[EXIT_BUTTON]);
	clean_img(init, img[PLAY_BUTTON_SELECTED]);
	clean_img(init, img[ONLINE_BUTTON_SELECTED]);
	clean_img(init, img[OPTION_BUTTON_SELECTED]);
	clean_img(init, img[EXIT_BUTTON_SELECTED]);
	clean_img(init, img[INVENTORY_BACKGROUND]);
	clean_img(init, img[MINIMAP_HEADER]);
	clean_img(init, img[OPTIONS_HEADER]);
	clean_img(init, img[SLIDER_BASE]);
	clean_img(init, img[SLIDER_SELECTED]);
	clean_img(init, img[SWITCH_ON]);
	clean_img(init, img[SWITCH_OFF]);
	clean_img(init, img[SWITCH_SELECTED]);
	clean_img(init, img[PROGRESS_START]);
	clean_img(init, img[PROGRESS_CENTER]);
	clean_img(init, img[PROGRESS_END]);
	clean_hud_game(img, init);
}

void	clean_texture(t_image *text, mlx_image *img, mlx_context init)
{
	clean_image(&text[NORTH], init);
	clean_image(&text[EAST], init);
	clean_image(&text[SOUTH], init);
	clean_image(&text[WEST], init);
	clean_image(&text[SKY], init);
	clean_image(&text[GROUND], init);
	clean_image(&text[BATTERY], init);
	clean_image(&text[DOOR], init);
	clean_image(&text[EXIT], init);
	mlx_destroy_image(init, img[RENDER]);
	mlx_destroy_image(init, img[RENDER_TMP]);
	clean_hud(img, init);
}
