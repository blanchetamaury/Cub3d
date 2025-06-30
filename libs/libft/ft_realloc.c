/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:24:22 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/30 10:22:27 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	size_t	len;
	void	*new;

	len = ft_strlen(ptr);
	if (len - size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(sizeof(void *) * (size + len));
	if (new == 0)
	{
		free(ptr);
		return (NULL);
	}
	ft_memset(new, 0, (size + len));
	ft_memmove(new, ptr, (size + len));
	free(ptr);
	return (new);
}

void	*ft_realloc_h(void *ptr, size_t new_size)
{
	t_header	*old_h;
	size_t		old_size_bytes;
	void		*new_block;

	new_block = malloc(new_size);
	old_h = (t_header *)ptr;
	old_size_bytes = sizeof(t_header) + old_h->capacity * sizeof(char *);
	if (new_block == NULL)
		return (NULL);
	if (!new_block)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_block, ptr, old_size_bytes);
	if (new_size > old_size_bytes)
		ft_memset((char *)new_block + old_size_bytes, 0,
			new_size - old_size_bytes);
	free(ptr);
	return (new_block);
}
