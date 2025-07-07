/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 08:55:14 by rgodet            #+#    #+#             */
/*   Updated: 2025/07/07 09:21:12 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	log_error(const char *message)
{
	int	len;

	len = write(2, "\e[41;1m ERROR \e[0m ", 20);
	if (message)
		len += write(2, message, ft_strlen(message));
	else
		len += write(2, "An error occurred.", 18);
	len += write(1, "\n", 1);
	return (len);
}
