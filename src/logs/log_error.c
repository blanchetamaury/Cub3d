/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:55:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/08/01 10:17:03 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	log_error(const char *message)
{
	int	len;

	len = write(2, "\e[31;1mError\e[0m\n", 17);
	if (message)
		len += write(2, message, ft_strlen(message));
	else
		len += write(2, "An error occurred.", 18);
	len += write(1, "\n", 1);
	return (len);
}
