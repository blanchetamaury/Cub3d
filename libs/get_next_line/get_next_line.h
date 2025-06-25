/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:05:43 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 11:40:49 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_memset_gnl(char *s, int c, size_t n);
void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *str, char *src, int len);
size_t	ft_strlen_gnl(char *s);

#endif
