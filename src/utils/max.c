/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:14:30 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/21 15:42:27 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

uint8_t	maxu(uint8_t a, uint8_t b)
{
	if (a > b)
		return (a);
	return (b);
}
