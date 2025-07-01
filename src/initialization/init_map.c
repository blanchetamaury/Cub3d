/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:28:03 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/01 13:28:54 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map   *init_map()
{
    t_map   *map;

    map = ft_calloc(1, sizeof(t_map));
    map->fd_map = -1;
    map->name = NULL;
    map->map = NULL;
    return (map);
}