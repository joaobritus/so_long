/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/04 15:42:45 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define MLX_ERROR 1

char	**treatment(char *argv, t_size *size)
{
	int		y;
	int		fd;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("fd fucked up");
		return (NULL);
	}
	*size = map_size(fd);
	map = malloc(sizeof(char *) * (size->y + 1));
	if (map == NULL)
	{
		perror("malloc fucked up");
		return (0);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	y = -1;
	while (++y < size->y)
		map[y] = get_next_line(fd);
	map[y] = 0;
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	t_size	size;
	t_size	player;

	if (argc != 2)
		return (1);
	i = -1;
	map = treatment(argv[1], &size);
	if (!map)
		return (2);
	if (map_valid(map, size, &player))
		return (0);
	startup(map, size, player);
	free_map(map);
	return (0);
}
