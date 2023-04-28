/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:31:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/04/28 18:24:12 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_the_player(char **map, t_size size, t_size *player)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < size.y)
	{
		while (++x < size.x)
		{
			if (map[y][x] == 'P')
			{
				*player.y == y;
				*player.x == x;
			}
		}
	}
}



int	flood_fill(char **map, t_size size, t_size player)
{
	if ((map[player.x][player.y] != '0' && map[player.x][player.y] != 'C'
	&& map[player.x][player.y] != 'P' && map[player.x][player.y] != 'E'
	&& map[player.x][player.y] != 'B')
	|| player.x < 0 || player.y < 0 || player.x >= size.x || player.y >= size.y)
		return ;
	if (map[player.x][player.y] == 'E')
		map[player.x][player.y] = 'e';
	if (map[player.x][player.y] == 'B')
		map[player.x][player.y] = 'b';
	if (map[player.x][player.y] == 'P')
		map[player.x][player.y] = 'p';
	if (map[player.x][player.y] == 'C')
		map[player.x][player.y] = 'c';
	if (map[player.x][player.y] == '0')
		map[player.x][player.y] = 'o';
	check_path(map, size, (t_coord){player.x + 1, player.y});
	check_path(map, size, (t_coord){player.x - 1, player.y});
	check_path(map, size, (t_coord){player.x, player.y + 1});
	check_path(map, size, (t_coord){player.x, player.y - 1});
}

int	walls(char **map, t_size size)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (size.x <= size.y)
		return (0);
	while (++y <= size.y)
	{
		if ((map[y][0] != '1') || (map[y][size.y] != '1'))
			return (0);
		if (y == 0 || y == size.y)
		{
			while (++x <= size.x)
			{
				if (map[y][x] != '1')
					return (0);
			}
			x = -1;
		}
	}
	return (1);
}

int	is_it_a_square(t_size size)
{
	int	y;

	y = -1;
	while (++y <= size.y)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[y + 1]))
			return (0);
	}
	return (1);
}

int	map_valid(char **map, t_size size, t_size *player)
{
	if ((player_number(map, size) != 1) || (exit_number(map, size) != 1)
		|| (collectible_number(map, size) < 1) || (!is_it_a_square(size))
		|| (!walls(map, size)))
		return (0);
	get_the_player(map, size, &player);
	if (!flood_fill(map, size, player))
		return (0);
	return (1);
}
