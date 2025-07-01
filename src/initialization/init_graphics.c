/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:24:40 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/01 13:24:58 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = ft_calloc(1, sizeof(t_graphics));
	return (graphics);
}