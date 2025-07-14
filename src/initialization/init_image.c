/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:48:47 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/14 09:51:10 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_image	*init_image(void)
{
	t_image	*image;

	image = ft_calloc(1, sizeof(t_image));
	image->path = NULL;
	image->img = NULL;
	image->width = -1;
	image->height = -1;
	return (image);
}
