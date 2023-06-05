/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:58:37 by jaragao-          #+#    #+#             */
/*   Updated: 2023/01/25 15:54:31 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line = ft_strjoin2(line, buffer[fd]);
	if (ft_strchar(buffer[fd], '\n'))
	{
		ft_index(buffer[fd]);
		return (line);
	}
	ft_index(buffer[fd]);
	if (read(fd, 0, 0) < 0)
		return (filed(line));
	while (read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin2(line, buffer[fd]);
		if (ft_strchar(buffer[fd], '\n'))
			break ;
		ft_index(buffer[fd]);
	}
	ft_index(buffer[fd]);
	return (line);
}
