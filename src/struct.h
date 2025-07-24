/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:58:27 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/24 14:03:14 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	char		*string_color;
	mlx_color	color;
}				t_color;

typedef struct s_image
{
	char		*path;
	mlx_image	img;
	int			width;
	int			height;
	mlx_color	*colors;
}				t_image;

typedef enum s_list_text
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	SKY,
	GROUND,
	BATTERY,
	DOOR,
	EXIT,
	GHOST,
	SIZE_LIST_TEXT,
}	t_list_text;

typedef	enum s_list_img
{
	RENDER,
	RENDER_TMP,
	COMPASS_BACKGROUND,
	COMPASS_INDICATOR,
	CLOCK_BACKGROUND,
	HANDS,
	CUB3D_LOGO,
	PLAY_BUTTON,
	PLAY_BUTTON_SELECTED,
	ONLINE_BUTTON,
	ONLINE_BUTTON_SELECTED,
	OPTION_BUTTON,
	OPTION_BUTTON_SELECTED,
	EXIT_BUTTON,
	EXIT_BUTTON_SELECTED,
	INVENTORY_BACKGROUND,
	INVENTORY_ICON_MAP,
	INVENTORY_ICON_CASES,
	INVENTORY_ICON_SAVE,
	INVENTORY_ICON_OPTIONS,
	INVENTORY_ICON_MAP_SELECTED,
	INVENTORY_ICON_CASES_SELECTED,
	INVENTORY_ICON_SAVE_SELECTED,
	INVENTORY_ICON_OPTIONS_SELECTED,
	Q_ARROW,
	E_ARROW,
	MINIMAP_HEADER,
	OPTIONS_HEADER,
	SLIDER_BASE,
	SLIDER_SELECTED,
	SWITCH_ON,
	SWITCH_OFF,
	SWITCH_SELECTED,
	PROGRESS_START,
	PROGRESS_CENTER,
	PROGRESS_END,
	MAP_T,
	MAP_B,
	MAP_L,
	MAP_R,
	MAP_P,
	FLASH_PANEL,
	LED_ON,
	FLASH_ON,
	FLASH_OFF,
	CROSSHAIR,
	SIZE_LIST_IMG,
}	t_list_img;

typedef struct s_graphics
{
	mlx_context				init;
	mlx_window				window;
	mlx_window_create_info	*info;
	int						view;
	int						frame;
	int						selection;
	struct timeval			last_time;
	double					fps;
	int						max_fps;
}				t_graphics;

typedef struct s_player
{
	int			x;
	int			y;
	float		pos_x;
	float		pos_y;
	float		rad;
	float		angle;
	float		base_angle;
	int			inventory_page;
	int			selected_item;
	int			use_mouse_rotation;
	int			battery;
}				t_player;

typedef struct s_map
{
	int			fd_map;
	char		*name;
	char		**map;
	int			size;
	int			cap;
}				t_map;

typedef struct s_raycasting
{
	int			fov;
	float		cos_x;
	float		sin_y;
	float		ray_x;
	float		ray_y;
	float		raylength_x;
	float		raylength_y;
	float		rofract_x;
	float		rofract_y;
	float		perpwalldist;
	int			draw_start;
	int			draw_end;
	float		color_x;
	float		color_y;
	int			tex_y;
	int			tex_x;
	float		wall_x;
	float		tex_step;
	float		tex_pos;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	float		floorstep_x;
	float		floorstep_y;
	float		floor_x;
	float		floor_y;
	int			tx;
	int			ty;
	float		deltaangle;
	float		deg_to_rad;
	float		transform_y;
	float		transform_x;
	int			sprite_height;
	int			sprite_width;
	int			i;
	int			door;
	int			frame;
	int			light;
	int			count_frame;
	int			time_s;
	int			count_bot;
}				t_raycasting;

typedef struct s_events
{
	int		move_forward;
	int		move_backward;
	int		move_left;
	int		move_right;
	int		flashlight;
	int		rotate_left;
	int		rotate_right;
	int		exit;
	int		debug_enabled;
	int		inventory;
}	t_events;

typedef struct s_rect
{
	int	x;
	int	y;
	int	h;
	int	w;
}			t_rect;

typedef	struct s_bot
{
	float		pos_x;
	float		pos_y;
	float		dead_light;
}				t_bot;

typedef struct s_game
{
	mlx_image		img[SIZE_LIST_IMG];
	t_image			text[SIZE_LIST_TEXT];
	t_graphics		*graphics;
	t_map			*map;
	t_player		*player;
	t_raycasting	*ray;
	t_events		*events;
	t_bot			bot[NB_BOT];
}					t_game;

#endif