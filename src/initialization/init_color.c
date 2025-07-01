/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:15:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/01 13:25:57 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_color	*init_color(void)
{
	t_color	*color;

	color = ft_calloc(1, sizeof(t_color));
	color->string_color = NULL;
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}
