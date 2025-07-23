/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:21:35 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/23 19:58:36 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = ft_calloc(1, sizeof(t_texture));
	texture->north = init_image();
	texture->east = init_image();
	texture->south = init_image();
	texture->west = init_image();
	texture->sky = init_image();
	texture->ground = init_image();
	texture->battery = init_image();
	texture->door = init_image();
	texture->exit = init_image();
	return (texture);
}
