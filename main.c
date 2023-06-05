/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/05 13:29:57 by jaragao-         ###   ########.fr       */
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

	map = get_size(argv, size);
	if (size->x == 0 || size->y == 0)
	{
		ft_printf("Map is empty\n");
		free(map);
		exit(1);
	}
	fd = open(argv, O_RDONLY);
	y = -1;
	while (++y < size->y)
	{
		map[y] = get_next_line(fd);
		if ((map[y] == 0 && y < size->y) || map[y][0] == '\n')
		{
			ft_printf("Found empty line\n");
			free_map(map);
			return (0);
		}
	}
	return (map);
}

char	**get_size(char *argv, t_size *size)
{
	int		fd;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("fd fucked up");
		return (NULL);
	}
	*size = map_size(fd);
	map = ft_calloc(sizeof(char *), (size->y + 1));
	if (map == NULL)
	{
		perror("malloc fucked up");
		return (0);
	}
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;
	t_size	size;
	t_size	player;

	i = 0;
	if (argc != 2)
		return (ft_printf("There has to be only 2 arguments"));
	while (argv[1][i])
		i++;
	if (ft_strncmp(&argv[1][i - 4], ".ber", 4))
		return (ft_printf("Map has to be .ber"));
	map = treatment(argv[1], &size);
	if (!map)
		return (2);
	if (map_valid(map, size, &player))
		return (0);
	startup(map, size, player);
	free_map(map);
	return (0);
}
