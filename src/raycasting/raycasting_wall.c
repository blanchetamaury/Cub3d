/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 09:54:16 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/17 13:51:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_wall(t_game *game, int *status)
{
	int	j;
	int	side;
	int map_x;
	int	map_y;

	j = 0;
	side = 0;
	map_x = game->ray->map_x;
	map_y = game->ray->map_y;
	while (1)
	{
		if (game->map->map[map_y][map_x] == 'B')
			*status = 1;
		if (game->map->map[game->ray->map_y][game->ray->map_x] == '1')
			break ;
		if (game->ray->raylength_x < game->ray->raylength_y)
		{
			game->ray->map_x += game->ray->step_x;
			game->ray->raylength_x += game->ray->ray_x;
			map_x += game->ray->step_x + 0.95;
			side = 0;
		}
		else
		{
			game->ray->map_y += game->ray->step_y;
			game->ray->raylength_y += game->ray->ray_y;
			map_y +=  game->ray->step_y + 0.95;
			side = 1;
		}
		j++;
	}
	return (side);
}

int	draw_size_wall(t_game *game, int side, int i)
{
	int		lineheight;
	float	camera_x;
	float	half_fov;
	float	angle_diff;

	camera_x = 2.0f * i / (float)WIDTH_WINDOW - 1.0f;
	half_fov = (game->ray->fov / 2) * (3.14 / 180.0f);
	angle_diff = camera_x * half_fov;
	if (side == 0)
		game->ray->perpwalldist = (game->ray->raylength_x - game->ray->ray_x)
			* cosf(angle_diff);
	else
		game->ray->perpwalldist = (game->ray->raylength_y - game->ray->ray_y)
			* cosf(angle_diff);
	if (game->ray->perpwalldist == 0)
		game->ray->perpwalldist = 1 * cosf(angle_diff);
	lineheight = (int)(HEIGHT_WINDOW / game->ray->perpwalldist);
	game->ray->draw_start = -lineheight / 2 + HEIGHT_WINDOW / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = lineheight / 2 + HEIGHT_WINDOW / 2;
	if (game->ray->draw_end >= HEIGHT_WINDOW)
		game->ray->draw_end = HEIGHT_WINDOW - 1;
	return (lineheight);
}

void	raycasting_wall(t_game *game)
{
	int		i;
	int		side;
	int		lineheight;
	int		count;
	int		status;
	static	float	z_buffer[WIDTH_WINDOW];
	
	mlx_color	color[HEIGHT_WINDOW * 1];

	i = 0;
	status = 0;
	while (i < WIDTH_WINDOW)
	{
		init_calc(game, init_angle(game, i));
		init_dir(game);
		side = find_wall(game, &status);
		if (game->ray->map_x - game->player->pos_x < 9 && game->ray->map_x - game->player->pos_x > -9 && game->ray->map_y - game->player->pos_y < 9 && game->ray->map_y - game->player->pos_y > -9)
		{
			lineheight = draw_size_wall(game, side, i);
			game->ray->color_x = (float)i - WIDTH_WINDOW / 3 - 60;
			wall_size_texture(game, side, lineheight);
			draw_wall(game, game->ray->draw_start, side, i);
			count = 0;
			mlx_get_image_region(game->graphics->init, game->texture->render, i, 0, 1, HEIGHT_WINDOW, color);
			while (count < 6)
			{
				mlx_set_image_region(game->graphics->init, game->texture->render, i + count, 0, 1, HEIGHT_WINDOW, color);
				z_buffer[i + count] = game->ray->perpwalldist;
				count++;
			}
			i += count;
		}
		else
		{
			z_buffer[i] = game->ray->perpwalldist;
			i++;
		}
	}

	int len;
	int y;
	int x;
	
	i = 0;
	len = 0;
	y = 0;
	while (game->map->map[y] && status == 1)
	{
		x = 0;
		while (game->map->map[y][x])
		{
			if (game->map->map[y][x] == 'B')
			{
				float			tan_half_fov;
				float			dir_x = 0;
				float			dir_y = 0;
				float			plane_x;
				float			plane_y;
				
				init_rad_floor(game, &dir_x, &dir_y);
				tan_half_fov = tanf((FOV / 2) * (3.14 / 180.0f));
				plane_x = -dir_y * tan_half_fov;
				plane_y = dir_x * tan_half_fov;
				float	sprite_x = x - game->player->pos_x + 0.5;
				float	sprite_y = y - game->player->pos_y + 0.5;
				float	invdet = 1.0f / (plane_x * dir_y - dir_x * plane_y);
				float	transform_x = invdet * (dir_y * sprite_x - dir_x * sprite_y);
				float	transform_y = invdet * (-plane_y* sprite_x + plane_x * sprite_y);
				int sprite_screen_x = (int)WIDTH_WINDOW / 2 * (1 + transform_x / transform_y);
				int sprite_height = abs((int)(HEIGHT_WINDOW / transform_y)) / 3;
				game->ray->draw_start = -sprite_height / 2 + HEIGHT_WINDOW / 2 + sprite_height;
				if (game->ray->draw_start < 0)
					game->ray->draw_start = 0;
				game->ray->draw_end = sprite_height / 2 + HEIGHT_WINDOW / 2 + sprite_height;
				if (game->ray->draw_end >= HEIGHT_WINDOW)
					game->ray->draw_end = HEIGHT_WINDOW - 1;
				int sprite_width = abs((int)(HEIGHT_WINDOW / transform_y)) / 3;
				int draw_start_x = -sprite_width / 2 + sprite_screen_x;
				if (draw_start_x < 0)
					draw_start_x = 0;
				int draw_end_x = sprite_width / 2 + sprite_screen_x;
				if (draw_end_x >= WIDTH_WINDOW)
					draw_end_x = WIDTH_WINDOW - 1;	
				len = draw_start_x;
				while (len < draw_end_x)
				{
					int k;

					k = game->ray->draw_start;
					int  tex_x = (len - draw_start_x) * game->texture->battery->width / sprite_width;
					if (transform_y <= 0 || transform_y >= z_buffer[len])
    					;
					else
					{
						while (k < game->ray->draw_end)
						{
							float		color_alpha;
							color_alpha = 1.0f - (transform_y / LIGHT);
							float intensity    = (2.0f + game->events->flashlight * 4.0f) * color_alpha;
							int  tex_y = (k   - game->ray->draw_start) * game->texture->battery->height / sprite_height;
							int idx   = tex_y * game->texture->battery->width + tex_x;
							mlx_color raw = game->texture->battery->colors[idx];
							unsigned avg  = (raw.r + raw.g + raw.b) / 3;
							if (avg < 20 || raw.a * intensity < 255)
							{
								raw.r = 0;
								raw.g = 0;
								raw.b = 0;
    						}
							else
							{
								raw.a = raw.a * intensity;
    						}
    						if (raw.a)
							{
        						mlx_set_image_pixel(game->graphics->init, game->texture->render, len, k, raw);
							}
							k++;
						}
					}
					len++;
				}
			}
			x++;	
		}
		y++;
	}
}
