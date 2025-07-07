/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:20:24 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/07 09:43:11 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	convert_to_rgb_condition(t_color *color, char **tab,
					int *status, int i)
{
	if (i == 3 && *status == 1)
	{
		color->r = ft_atoi(tab[0]);
		if (color->r < 0 || check_number(tab[0]) == 0)
			*status = 0;
		color->g = ft_atoi(tab[1]);
		if (color->g < 0 || check_number(tab[1]) == 0)
			*status = 0;
		color->b = ft_atoi(tab[2]);
		if (color->b < 0 || check_number(tab[2]) == 0)
			*status = 0;
	}
	else
		*status = 0;
}

static void	convert_to_rgb(t_color *color, int *status)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(color->string_color, ',');
	while (tab[i])
	{
		if (tab[i] == NULL)
			*status = 0;
		i++;
	}
	convert_to_rgb_condition(color, tab, status, i);
	if (*status == 1 && (float)(color->r + color->g + color->b) / 3 > 255)
		*status = 0;
	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
}

int	check_ground_and_sky(t_game *game, int count)
{
	int	status;

	status = 1;
	if (count != 6)
		return (log_error("A texture is missing. All of these are required : NO, SO, WE, EA, F, C"));
	convert_to_rgb(game->texture->ground, &status);
	convert_to_rgb(game->texture->sky, &status);
	if (status == 0)
		return (log_error("Failed to parse color. Is it in right format ?"));
	return (0);
}
