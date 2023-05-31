/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:31:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/31 17:11:18 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_size	map_size(int fd)
{
	char	buffer;
	t_size	i;

	i.x = 0;
	i.y = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (i.y == 0 && buffer != '\n')
			i.x++;
		if (buffer == '\n')
			i.y++;
	}
	i.y++;
	if (read(fd, &buffer, 1) == -1)
		return ((t_size){0, 0});
	return (i);
}

int	walls(char **map, t_size size)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size.y)
	{
		if ((map[y][0] != '1') || (map[y][size.x - 1] != '1'))
			return (0);
	}
	x = -1;
	while (++x < size.x)
	{
		if ((map[0][x] != '1') || (map[size.y - 1][x] != '1'))
			return (0);
	}
	return (1);
}

int	is_it_a_square(char **map)
{
	int	x;
	int	y;
	int	z;
	int	w;

	y = 0;
	z = 0;
	x = -1;
	while (map[0][++x] && map[0][x] != '\n')
		z++;
	while (map[++y])
	{
		x = -1;
		w = 0;
		while (map[y][++x] && map[y][x] != '\n')
			w++;
		if (w != z)
			return (0);
	}
	return (1);
}

int	map_valid(char **map, t_size size, t_size *player)
{	
	get_the_player(map, size, player);
	if (!is_it_a_square(map))
		return (printf("Error/n Map is not a square"));
	if (exit_number(map, size) != 1)
		return (printf("Error/n There has to be only one exit"));
	if (player_number(map, size) != 1)
		return (printf("Error/n There has to be only one player"));
	if (collectible_number(map, size) < 1)
		return (printf("Error/n There has to be at least one collectible"));
	if (!walls(map, size))
		return (printf("Error/n Map is not sorrounded by walls"));
	flood_fill(map, size, *player);
	if (!check_map(map))
		return (1);
	reset_map(map);
	return (0);
}
