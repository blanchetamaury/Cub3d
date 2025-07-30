/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:57:29 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/30 13:40:04 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_color(char	**color)
{
	int	i;
	int	j;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (color[i][j] < '0' || color[i][j] > '9')
			{
				log_error("Invalid character in color string.");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		log_error("Invalid color format. Expected 3 components (R,G,B).");
		return (1);
	}
	return (0);
}

static void	create_mlx_image(t_image *image, mlx_context init)
{
	image->width = 1;
	image->height = 1;
	image->img = mlx_new_image(init, image->width, image->height);
}

static void	color_image(t_image *image, mlx_context init)
{
	char		**tab;
	mlx_color	color;

	tab = ft_split(image->path, ',');
	if (!tab)
		return ;
	if (check_color(tab) == 1)
		return ;
	if (ft_atoi_8bit(tab[0]) < 0 || ft_atoi_8bit(tab[1]) < 0
		|| ft_atoi_8bit(tab[2]) < 0)
	{
		log_error("Color values must be between 0 and 255.");
		return ;
	}
	create_mlx_image(image, init);
	if (image->img == NULL)
	{
		log_error("Failed to create image from color.");
		return ;
	}
	color.r = ft_atoi_8bit(tab[0]);
	color.g = ft_atoi_8bit(tab[1]);
	color.b = ft_atoi_8bit(tab[2]);
	color.a = 255;
	mlx_set_image_pixel(init, image->img, 0, 0, color);
}

static void	image_file(t_image *image, mlx_context init)
{
	image->img = mlx_new_image_from_file(init, image->path, &image->width,
			&image->height);
	if (image->img == NULL)
		log_error("Failed to open image file.");
}

int	verif_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count == 3)
		return (1);
	return (0);
}

int	open_image(t_image *image, mlx_context init)
{
	int	type;

	if (image->path == NULL)
		return (0);
	if (ft_strchr(image->path, ',') == NULL)
	{
		image_file(image, init);
		type = 1;
	}
	else
	{
		type = 2;
		if (verif_comma(image->path) == 0)
			return (2);
		color_image(image, init);
	}
	image->colors = ft_calloc(image->width * image->height, sizeof(mlx_color));
	mlx_get_image_region(init, image->img, 0, 0, image->width,
		image->height, image->colors);
	return (type);
}
